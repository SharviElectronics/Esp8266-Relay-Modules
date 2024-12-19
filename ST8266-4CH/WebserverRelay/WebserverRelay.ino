#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Replace these with your network credentials
const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

// Create an instance of the web server on port 80
ESP8266WebServer server(80);

// GPIO pins for the relays
const int relayPin1 = 16;  // GPIO16
const int relayPin2 = 14;  // GPIO14
const int relayPin3 = 12;  // GPIO12
const int relayPin4 = 13;  // GPIO13

void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);
  
  // Set relay pins as output
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(relayPin3, OUTPUT);
  pinMode(relayPin4, OUTPUT);
  
  // Initially turn off all relays
  digitalWrite(relayPin1, LOW);
  digitalWrite(relayPin2, LOW);
  digitalWrite(relayPin3, LOW);
  digitalWrite(relayPin4, LOW);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi!");

  // Define routes for controlling relays
  server.on("/", HTTP_GET, handleRoot);  // Home page
  server.on("/relay1/on", HTTP_GET, handleRelay1On);
  server.on("/relay1/off", HTTP_GET, handleRelay1Off);
  server.on("/relay2/on", HTTP_GET, handleRelay2On);
  server.on("/relay2/off", HTTP_GET, handleRelay2Off);
  server.on("/relay3/on", HTTP_GET, handleRelay3On);
  server.on("/relay3/off", HTTP_GET, handleRelay3Off);
  server.on("/relay4/on", HTTP_GET, handleRelay4On);
  server.on("/relay4/off", HTTP_GET, handleRelay4Off);

  // Start the server
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // Handle incoming client requests
  server.handleClient();
}

void handleRoot() {
  String html = "<html><body>";
  html += "<h1>ESP8266 Relay Control</h1>";
  html += "<p><a href='/relay1/on'>Turn Relay 1 ON</a> | <a href='/relay1/off'>Turn Relay 1 OFF</a></p>";
  html += "<p><a href='/relay2/on'>Turn Relay 2 ON</a> | <a href='/relay2/off'>Turn Relay 2 OFF</a></p>";
  html += "<p><a href='/relay3/on'>Turn Relay 3 ON</a> | <a href='/relay3/off'>Turn Relay 3 OFF</a></p>";
  html += "<p><a href='/relay4/on'>Turn Relay 4 ON</a> | <a href='/relay4/off'>Turn Relay 4 OFF</a></p>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleRelay1On() {
  digitalWrite(relayPin1, HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleRelay1Off() {
  digitalWrite(relayPin1, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleRelay2On() {
  digitalWrite(relayPin2, HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleRelay2Off() {
  digitalWrite(relayPin2, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleRelay3On() {
  digitalWrite(relayPin3, HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleRelay3Off() {
  digitalWrite(relayPin3, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleRelay4On() {
  digitalWrite(relayPin4, HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleRelay4Off() {
  digitalWrite(relayPin4, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}
