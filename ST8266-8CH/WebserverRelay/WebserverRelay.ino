#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// Replace these with your network credentials
const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

// Create an instance of the web server on port 80
ESP8266WebServer server(80);

// GPIO pins for the 8 relays
const int relayPins[] = {16, 14, 12, 13, 15, 10, 4, 5};  // Use appropriate GPIO pins (D0-D7)

// Function to set up the relay pins
void setupRelays() {
  for (int i = 0; i < 8; i++) {
    pinMode(relayPins[i], OUTPUT);
    digitalWrite(relayPins[i], LOW);  // Turn off all relays initially
  }
}

void setup() {
  // Start serial communication for debugging
  Serial.begin(115200);

  // Set up the relay pins
  setupRelays();

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi!");

  // Define routes for controlling the relays
  server.on("/", HTTP_GET, handleRoot);  // Home page

  // Routes for controlling each relay
  for (int i = 0; i < 8; i++) {
    server.on("/relay" + String(i + 1) + "/on", HTTP_GET, [i](){ handleRelayOn(i); });
    server.on("/relay" + String(i + 1) + "/off", HTTP_GET, [i](){ handleRelayOff(i); });
  }

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
  html += "<h1>ESP8266 8-Channel Relay Control</h1>";

  // Generate links for each relay
  for (int i = 0; i < 8; i++) {
    html += "<p><a href='/relay" + String(i + 1) + "/on'>Turn Relay " + String(i + 1) + " ON</a> | "
            "<a href='/relay" + String(i + 1) + "/off'>Turn Relay " + String(i + 1) + " OFF</a></p>";
  }

  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleRelayOn(int relayIndex) {
  digitalWrite(relayPins[relayIndex], HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleRelayOff(int relayIndex) {
  digitalWrite(relayPins[relayIndex], LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}
