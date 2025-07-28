#include <TinyGPS++.h>      // Library for parsing GPS data, Download the TinyGPSPlus by Mikal Hart
#include <SoftwareSerial.h> // Allows serial communication on non-hardware serial pins

// Define the RX and TX pins for communication with the GPS module
static const int RXPin = 2, TXPin = 3; 

// Define the baud rate for GPS module communication
static const uint32_t BaudRate = 9600;

// Create a TinyGPS++ object to store and process GPS data
TinyGPSPlus gps;

// Create a software serial port for GPS communication
SoftwareSerial gpsSerial(RXPin, TXPin);

void setup() {
    Serial.begin(115200);  // Initialize serial communication with the computer for debugging
    gpsSerial.begin(BaudRate); // Start software serial communication with GPS module

    Serial.println("GPS Module Initializing..."); // Print status message
}

void loop() {
    // Check if there is incoming data from the GPS module
    while (gpsSerial.available() > 0) {
        gps.encode(gpsSerial.read()); // Read and process GPS data

        // If new location data is available, print latitude and longitude
        if (gps.location.isUpdated()) { 
            Serial.print("Latitude: ");
            Serial.print(gps.location.lat(), 6);  // Print latitude with 6 decimal places
            Serial.print(", Longitude: ");
            Serial.println(gps.location.lng(), 6); // Print longitude with 6 decimal places
        }

        // If new satellite data is available, print the number of connected satellites
        if (gps.satellites.isUpdated()) { 
            Serial.print("Satellites: ");
            Serial.println(gps.satellites.value()); // Print the number of satellites in view
        }

        // If new altitude data is available, print the altitude
        if (gps.altitude.isUpdated()) { 
            Serial.print("Altitude: ");
            Serial.print(gps.altitude.meters()); // Print altitude in meters
            Serial.println(" m");
        }
    }
}
