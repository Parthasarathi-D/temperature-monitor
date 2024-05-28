#include <ESP8266WiFi.h>
#include <DHT.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <ESP8266HTTPClient.h>

// WiFi credentials
const char* ssid = "Hermoine";
const char* password = "98765432";

// Flask server URL
const char* serverUrl = "http://172.20.10.4:5000/receive_data"; // Use the Flask server's IP and port

// DHT sensor setup
DHT dht(D4, DHT11); // Change pin and sensor type as necessary

// GPS setup
TinyGPSPlus gps;
SoftwareSerial ss(D5, D6); // RX, TX for GPS

// Default values
const float DEFAULT_TEMPERATURE = 32.0; // Default temperature value
const float DEFAULT_LATITUDE = 0.0; // Default latitude value
const float DEFAULT_LONGITUDE = 0.0; // Default longitude value

WiFiClient wifiClient;

void setup() {
  Serial.begin(115200);
  ss.begin(9600);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float latitude = DEFAULT_LATITUDE;
  float longitude = DEFAULT_LONGITUDE;

  // Read GPS data
  while (ss.available() > 0) {
    if (gps.encode(ss.read())) {
      if (gps.location.isUpdated()) {
        latitude = gps.location.lat();
        longitude = gps.location.lng();
      }
    }
  }

  // Use default temperature if read value is NaN
  if (isnan(temperature)) {
    temperature = DEFAULT_TEMPERATURE;
  }

  // Create the payload
  String payload = "{\"temperature\":\"" + String(temperature) + "\",\"latitude\":\"" + String(latitude, 6) + "\",\"longitude\":\"" + String(longitude, 6) + "\"}";

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(wifiClient, serverUrl); // Use the Flask server URL
    http.addHeader("Content-Type", "application/json");

    Serial.println("Sending HTTP POST request...");
    Serial.println("Payload: ");
    Serial.println(payload);

    int httpResponseCode = http.POST(payload);
    if (httpResponseCode > 0) {
      Serial.print("HTTP response code: ");
      Serial.println(httpResponseCode);
      String response = http.getString();
      Serial.println("Response: ");
      Serial.println(response);
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
      Serial.println(http.errorToString(httpResponseCode));
    }
    http.end();
  } else {
    Serial.println("WiFi not connected!");
  }

  delay(10000); // Adjust this delay as needed
}
