#include <WiFiS3.h>  // Library for WiFi functionality, included with IDE

/////////////////////////////////////////////////
// WiFi configuration
const char* ssid = "TTUguest";          // WiFi network name (SSID)
const char* pass = "aspiringfoundation"; // WiFi password
WiFiServer server(12345);              // Initialize a WiFi server on port 12345
WiFiClient client;                     // Object to manage client connections
/////////////////////////////////////////////////

void setup() {
/////////////////////////////////////////////////
  Serial.begin(9600);  // Start serial communication at 9600 baud

  // Attempt to connect to WiFi
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, pass);  // Start the WiFi connection using the credentials
  
  // Wait for successful WiFi connection
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");  // Display progress dots during connection attempt
    delay(1000);
  }
  
  // Log connection details after successful connection
  Serial.println("\nConnected to WiFi");
  Serial.print("Arduino IP: ");
  Serial.println(WiFi.localIP());  // Display the Arduino's IP address
  
  server.begin();  // Start the WiFi server to listen for incoming connections
  Serial.println("Server started. Waiting for client connections.");
/////////////////////////////////////////////////
}

void loop() {
  // Check if a client is trying to connect to the server
  client = server.available();  // Get a client connection object if available
  
  if (client) {  // If a client successfully connects
    Serial.println("Client connected.");  // Log client connection
    
    // Handle communication with the client
    while (client.connected()) {  // While the client remains connected
      if (client.available()) {  // If the client sends data
        handleClientMessages();  // Process the client's message
      }
    }

    // Client disconnects after communication ends
    client.stop();  // Close the client connection
    Serial.println("Client disconnected.");
  }
}

void handleClientMessages() {
  // Read the incoming data from the client until a newline character is encountered
  String tempString = client.readStringUntil('\n');  

  // Log the received message
  Serial.print("Received message: "); 
  Serial.println(tempString);

  // Add further logic here to process the message if needed
}
