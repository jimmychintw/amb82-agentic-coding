# ObjectDetection Class

## ObjectDetectionResult Class

### Description

A class used to represent and retrieve data related to objects recognized by an object detection neural network.

### Syntax

```cpp
class ObjectDetectionResult
```

### Members

| Method | Description |
|--------|-------------|
| `ObjectDetectionResult::type` | Get type index of recognized object |
| `ObjectDetectionResult::name` | Get name of recognized object |
| `ObjectDetectionResult::score` | Get confidence score of recognized object |
| `ObjectDetectionResult::xMin` | Get x coordinate of top left corner of bounding box |
| `ObjectDetectionResult::xMax` | Get x coordinate of bottom right corner of bounding box |
| `ObjectDetectionResult::yMin` | Get y coordinate of top left corner of bounding box |
| `ObjectDetectionResult::yMax` | Get y coordinate of bottom right corner of bounding box |

## ObjectDetectionResult::type

### Description

Get type index of recognized object, corresponding to the object category in the COCO image dataset.

### Syntax

```cpp
int type(void);
```

### Returns

An integer indicating the category of the recognized object.

## ObjectDetectionResult::name

### Description

Get name of recognized object.

### Syntax

```cpp
const char* name(void);
```

### Returns

A pointer to a character array containing the category name.

## ObjectDetectionResult::score

### Description

Get confidence score of recognized object.

### Syntax

```cpp
int score(void);
```

### Returns

An integer ranging from 0 to 100 representing the confidence.

## NNObjectDetection Class

### Description

A class used to configure, run, and retrieve results of an object detection neural network model.

### Syntax

```cpp
class NNObjectDetection
```

### Members

| Method | Description |
|--------|-------------|
| `NNObjectDetection::configVideo` | Configure input video stream parameters |
| `NNObjectDetection::configRegionOfInterest` | Configure object detection region of interest |
| `NNObjectDetection::configThreshold` | Configure object detection threshold |
| `NNObjectDetection::begin` | Start object detection process |
| `NNObjectDetection::end` | Stop object detection process |
| `NNObjectDetection::setResultCallback` | Set callback function for results |
| `NNObjectDetection::getResultCount` | Get number of results |
| `NNObjectDetection::getResult` | Get object detection results |

## NNObjectDetection::configVideo

### Description

Configure input video stream parameters.

### Syntax

```cpp
void configVideo(VideoSetting& config);
```

### Parameters

- `config`: VideoSetting class object containing desired video configuration

## NNObjectDetection::configThreshold

### Description

Configure object detection threshold.

### Syntax

```cpp
void configThreshold(float confidence_threshold, float nms_threshold);
```

### Parameters

- `confidence_threshold`: Object detection confidence threshold (default 0.5)
- `nms_threshold`: Non-Maximal Suppression threshold (default 0.3)

## NNObjectDetection::begin

### Description

Start object detection process on input video.

### Syntax

```cpp
void begin(void);
```

## NNObjectDetection::setResultCallback

### Description

Set a callback function to receive object detection results.

### Syntax

```cpp
void setResultCallback(void (*od_callback)(std::vector<ObjectDetectionResult>));
```

### Parameters

- `od_callback`: A callback function that accepts a vector of ObjectDetectionResult

## NNObjectDetection::getResultCount

### Description

Get number of object detection results.

### Syntax

```cpp
uint16_t getResultCount(void);
```

### Returns

The number of detected objects.

## NNObjectDetection::getResult

### Description

Get object detection results.

### Syntax

```cpp
ObjectDetectionResult getResult(uint16_t index);
std::vector<ObjectDetectionResult> getResult(void);
```

### Parameters

- `index`: Index of specific result to retrieve (optional)

### Returns

ObjectDetectionResult object(s).