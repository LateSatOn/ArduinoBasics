#include <WiFiS3.h>  // Library for WiFi functionality, included with IDE

/////////////////////////////////////////////////
// WiFi configuration
const char* ssid = "TTUguest";         // WiFi network name
const char* pass = "aspiringfoundation"; // WiFi password
WiFiServer server(12345);             // Initialize a WiFi server on port 12345
WiFiClient client;                    // Object to manage client connections
/////////////////////////////////////////////////

void setup() {
/////////////////////////////////////////////////
  Serial.begin(9600);  // Start serial communication at 9600 baud

  // Connect to WiFi
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, pass);  // Start WiFi connection with given credentials
  
  // Wait for WiFi connection
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");  // Print progress dots while connecting
    delay(1000);
  }
  
  // Print connection details once connected
  Serial.println("\nConnected to WiFi");
  Serial.print("Arduino IP: ");
  Serial.println(WiFi.localIP());  // Display the Arduino's IP address
  
  server.begin();  // Start the WiFi server
  Serial.println("Server started and waiting for connections.");
/////////////////////////////////////////////////
}

void loop() {
  // Check if a client has connected to the server
  WiFiClient client = server.available();  // Check for a client connection
  
  if (client) {  // If a client is connected
    Serial.println("Client connected.");  // Log client connection

    // Handle the client's connection
    while (client.connected()) {  // While the client remains connected
      if (client.available()) {  // Check if the client sent any data
        receivedChar = client.read();
        
        client.print(receivedChar); // Echo the received character back to the client

        handleMessage(receivedChar);  // Process the received character
      }
    }

    // Disconnect the client after the session ends
    client.stop();  // Close the client connection
    Serial.println("Client disconnected.");
  }
}

void handleMessage(char receivedChar) {
  // Log the received character
  Serial.print("Received: "); 
  Serial.println(receivedChar);

  // Process the character and perform specific actions
  switch (receivedChar) {
    case 'a':  // If 'a' is received
      Serial.println("Received an 'a', responding with 'A'.");
      break;
    case 'b':  // If 'b' is received
      Serial.println("Received a 'b', responding with 'B'.");
      break;
    // Add further Case logic here to process the message if needed
    default:  // Handle any unrecognized characters
      Serial.println("Unrecognized character received.");
  }
}