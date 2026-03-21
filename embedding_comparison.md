# AMB82 Mini 文件語意搜尋：兩種方案比較

## 共同部分

兩個方案都需要：
- **Embedding Model**: `paraphrase-multilingual-MiniLM-L12-v2`（約 120MB，中英文都支援）
- **預建流程**: 只需要跑一次，產生的索引檔案可以 commit 到 repo 裡，其他人 clone 下來直接用
- **搜尋時不需要 GPU**，CPU 就夠了

---

## 方案 A：numpy + pickle

### 概念
把所有文件的 embedding 向量算好，連同 metadata 一起用 pickle 存成一個檔案。搜尋時載入記憶體，用 numpy 算 cosine similarity。

### 依賴
```
pip install sentence-transformers numpy
```

### 預建索引（只需跑一次）
```python
# build_index.py
from sentence_transformers import SentenceTransformer
import numpy as np
import pickle
import os
import glob

model = SentenceTransformer('paraphrase-multilingual-MiniLM-L12-v2')

docs = []
for md_file in glob.glob('amb82_Info/**/*.md', recursive=True):
    with open(md_file, 'r', encoding='utf-8') as f:
        content = f.read()
    docs.append({
        'path': md_file,
        'title': content.split('\n')[0].replace('#', '').strip(),
        'content': content,
        # 把長文件切成 chunk（每 500 字一段）
        'chunks': [content[i:i+500] for i in range(0, len(content), 400)]  # 100字重疊
    })

# 算 embedding（對每個 chunk 算一個向量）
all_chunks = []
chunk_metadata = []
for doc in docs:
    for i, chunk in enumerate(doc['chunks']):
        all_chunks.append(chunk)
        chunk_metadata.append({
            'path': doc['path'],
            'title': doc['title'],
            'chunk_index': i
        })

embeddings = model.encode(all_chunks, show_progress_bar=True)

# 存檔
index = {
    'embeddings': np.array(embeddings),    # shape: (N, 384)
    'metadata': chunk_metadata,
    'docs': docs
}
with open('amb82_index.pkl', 'wb') as f:
    pickle.dump(index, f)

# 產出：一個 .pkl 檔案，大概 5-15MB
```

### MCP Server 中搜尋
```python
import numpy as np
import pickle

# 啟動時載入（幾百毫秒）
with open('amb82_index.pkl', 'rb') as f:
    index = pickle.load(f)

def search(query: str, top_k: int = 5):
    """搜尋最相關的文件片段"""
    query_embedding = model.encode([query])

    # cosine similarity
    scores = np.dot(index['embeddings'], query_embedding.T).flatten()
    top_indices = np.argsort(scores)[::-1][:top_k]

    results = []
    seen_paths = set()
    for idx in top_indices:
        meta = index['metadata'][idx]
        if meta['path'] not in seen_paths:  # 去重同一篇文件
            seen_paths.add(meta['path'])
            results.append({
                'path': meta['path'],
                'title': meta['title'],
                'score': float(scores[idx]),
                'snippet': index['docs'][meta['chunk_index']]['content'][:200]
            })
    return results

# 使用
results = search("怎麼用 BLE 傳感測器資料")
results = search("camera RTSP streaming setup")
results = search("deep sleep 省電模式")
```

### 檔案結構
```
amb82_agentic_coding/
├── amb82_index.pkl           # 預建的索引（5-15MB）
├── build_index.py            # 建索引的腳本
├── amb82_mcp/
│   └── server.py             # MCP Server
└── amb82_Info/
    ├── amb82-mini-docs/
    ├── ameba-arduino-pro2/
    └── ameba-rtos-pro2/
```

### 優缺點
```
✅ 零額外依賴（numpy 幾乎到處都有）
✅ 啟動極快（載入 pickle < 1 秒）
✅ 概念簡單，容易 debug
✅ 跨平台完全沒問題
✅ 索引檔案就一個 .pkl，容易管理

❌ 搜尋是暴力計算（但 180 篇文件根本不是問題）
❌ 沒有 filtering 功能（要自己寫）
❌ 如果文件更新，要重跑 build_index.py
❌ pickle 格式不夠標準化
```

---

## 方案 B：LanceDB

### 概念
LanceDB 是檔案型向量資料庫，資料存在一個目錄裡（Lance 格式）。
支援向量搜尋 + metadata filtering，有內建的 embedding function 整合。

### 依賴
```
pip install lancedb sentence-transformers
```

### 預建索引（只需跑一次）
```python
# build_index.py
import lancedb
from sentence_transformers import SentenceTransformer
import glob

model = SentenceTransformer('paraphrase-multilingual-MiniLM-L12-v2')

db = lancedb.connect('./amb82_lancedb')

# 準備資料
records = []
for md_file in glob.glob('amb82_Info/**/*.md', recursive=True):
    with open(md_file, 'r', encoding='utf-8') as f:
        content = f.read()

    title = content.split('\n')[0].replace('#', '').strip()

    # 判斷文件分類
    if '/amb82-mini-docs/02-examples/' in md_file:
        category = md_file.split('/02-examples/')[1].split('/')[0]  # wifi, ble, i2c...
        doc_type = 'example'
    elif '/amb82-mini-docs/03-api/' in md_file:
        category = md_file.split('/03-api/')[1].split('/')[0]
        doc_type = 'api'
    elif '/ameba-arduino-pro2/' in md_file:
        category = 'arduino-library'
        doc_type = 'source'
    elif '/ameba-rtos-pro2/' in md_file:
        category = 'rtos-sdk'
        doc_type = 'source'
    else:
        category = 'general'
        doc_type = 'doc'

    # 切 chunk
    chunks = [content[i:i+500] for i in range(0, len(content), 400)]

    for i, chunk in enumerate(chunks):
        embedding = model.encode(chunk).tolist()
        records.append({
            'vector': embedding,
            'path': md_file,
            'title': title,
            'category': category,
            'doc_type': doc_type,
            'chunk_index': i,
            'text': chunk
        })

# 寫入 LanceDB
table = db.create_table('docs', records, mode='overwrite')

# 產出：一個 amb82_lancedb/ 目錄，大概 10-20MB
```

### MCP Server 中搜尋
```python
import lancedb
from sentence_transformers import SentenceTransformer

model = SentenceTransformer('paraphrase-multilingual-MiniLM-L12-v2')

# 啟動時開啟（幾毫秒）
db = lancedb.connect('./amb82_lancedb')
table = db.open_table('docs')

def search(query: str, top_k: int = 5,
           category: str = None, doc_type: str = None):
    """搜尋最相關的文件片段，支援 metadata filtering"""
    query_embedding = model.encode(query).tolist()

    results = table.search(query_embedding).limit(top_k)

    # 可以加 filter 條件
    if category:
        results = results.where(f"category = '{category}'")
    if doc_type:
        results = results.where(f"doc_type = '{doc_type}'")

    return results.to_pandas()

# 使用
results = search("BLE sensor data transfer")
results = search("RTSP streaming", category="multimedia")
results = search("WiFi 連線", doc_type="example")      # 只搜範例
results = search("VideoStream class", doc_type="api")   # 只搜 API 文件
```

### 檔案結構
```
amb82_agentic_coding/
├── amb82_lancedb/              # LanceDB 資料目錄（10-20MB）
│   └── docs.lance/
├── build_index.py              # 建索引的腳本
├── amb82_mcp/
│   └── server.py               # MCP Server
└── amb82_Info/
    ├── amb82-mini-docs/
    ├── ameba-arduino-pro2/
    └── ameba-rtos-pro2/
```

### 優缺點
```
✅ 支援 metadata filtering（按分類、文件類型過濾）
✅ 資料格式標準化（Lance 格式，比 pickle 正式）
✅ 內建分頁、排序功能
✅ 未來擴充容易（加新欄位、新文件）
✅ 可以搭配 Pandas 做後處理
✅ 跨平台（純 Python wheel）

❌ 多一個 pip 依賴（lancedb）
❌ 資料存成目錄而非單一檔案
❌ 相對較新的專案（2023 年才開始）
❌ 如果文件更新，要重跑 build_index.py（跟方案 A 一樣）
```

---

## 並排比較

| 比較項目 | numpy + pickle | LanceDB |
|---------|---------------|---------|
| 額外依賴 | 無（numpy 通常已安裝） | `pip install lancedb` |
| 索引大小 | 5-15 MB（單一 .pkl 檔） | 10-20 MB（一個目錄） |
| 啟動速度 | < 1 秒 | < 1 秒 |
| 搜尋速度 | < 10ms（180篇文件） | < 10ms |
| Metadata 過濾 | 要自己寫 | 內建 `.where()` |
| 跨平台 | ✅ 完全沒問題 | ✅ 沒問題 |
| 學習成本 | 極低 | 低 |
| 未來擴充性 | 手動處理 | 較好（加欄位、索引等） |
| 成熟度 | numpy 很成熟 | 較新但活躍 |

## 我的建議

以你目前的場景（180 篇固定文件），兩個方案效果幾乎一樣。

- 如果你偏好**簡單直接、最少依賴** → 方案 A（numpy）
- 如果你想要**metadata filtering（按分類搜尋）** 且不介意多裝一個套件 → 方案 B（LanceDB）

不管選哪個，embedding model 都是用 `paraphrase-multilingual-MiniLM-L12-v2`，
預建索引都是跑一次 `build_index.py` 就好。
