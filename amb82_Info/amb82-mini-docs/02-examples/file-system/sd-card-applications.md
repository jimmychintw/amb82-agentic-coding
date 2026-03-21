# Simple Applications with SD Card

## Materials

- AMB82-mini x 1
- MicroSD card x 1

## Example

### Procedure

Insert a MicroSD card into the SD card slot of the AMB82 MINI board.

### Example 01 CreateFolder

Open the example, Files -> Examples -> AmebaFileSystem -> CreateFolder

Upload the code and press the reset button on the board once the upload is finished.

The sample code first creates a folder named "testdir", a text file named "test.txt" is next created, and the text "hello world!" is saved into the file. After that, the contents of the file are retrieved and printed to the serial monitor.

Using a card reader, connect the SD card to a computer, open the folder and the file to verify that the contents are as expected.

### Example 02 FileReadWrite

Open the example, Files -> Examples -> AmebaFileSystem -> FileReadWrite

Upload the code and press the reset button on the board once the upload is finished.

The sample code first creates a text file named "test.txt", then the text "hello world!" is saved into the file. After that, the contents of the file are retrieved and printed to the serial monitor.

### Example 03 GetFileAttribute

Open the example, Files -> Examples -> AmebaFileSystem -> GetFileAttribute

Upload the code and press the reset button on the board once the upload is finished.

The sample code reads the contents of a directory and determines if each item is a file or folder.

### Example 04 LastModifiedTime

Open the example, Files -> Examples -> AmebaFileSystem -> LastModifiedTime

Upload the code and press the reset button on the board once the upload is finished.

The sample code first opens the text file named "test.txt". After that, the last modified date and time of the file are changed and then printed to the serial monitor.

### Example 05 ListRootFiles

Open the example, Files -> Examples -> AmebaFileSystem -> ListRootFiles

Upload the code and press the reset button on the board once the upload is finished.

The sample code will print out the names of all files and folders in the root directory to the serial monitor.