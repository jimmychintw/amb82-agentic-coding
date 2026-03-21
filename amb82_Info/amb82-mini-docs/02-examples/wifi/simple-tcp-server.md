# Simple TCP Server

## Materials

- AMB82-mini x 1
- Laptop (connected to same network, with TCP tools installed)

## Example

In this example, we first connect Ameba to WiFi, then we use Ameba as server to communicate with client.

First, we make sure the correct Ameba development board is set in Tools -> Board

Then, open the Simple WiFi Server example in File -> Examples -> WiFi -> SimpleTCPServer

In the sample code, modify the highlighted parameters and enter the ssid and password for your WiFi connection.

Next, upload the code, then press the reset button on Ameba. Afterwards, you will see the connection information is displayed in the serial monitor.

Next, we use the socket tool in the laptop to be the client and connect to the IP address of the Ameba board shown in the connection information at port 5000.

Click on the "Client" tab to choose the client mode, specify the IP and port of the server, then click "TCP Connect".

If the connection is established successfully, the server shows a message: "A client connected to this Server", and the IP and port of the connected client.

In this example, when the client and server are connected and the client sends a string to Ameba server, the Ameba server returns the identical string back to the client.

## Code Reference

- `WiFi.begin()` - Establish WiFi connection
- `WiFi.SSID()` - Get SSID of current connected network
- `WiFi.RSSI()` - Get signal strength
- `WiFi.localIP()` - Get IP address
- `Server(port)` - Create a server on specified port
- `server.begin()` - Start listening for connections
- `server.available()` - Get client with data available
- `client.read()` - Read data from client
- `client.write()` - Write data to client
- `client.stop()` - Disconnect from server