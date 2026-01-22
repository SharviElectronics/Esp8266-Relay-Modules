/*
  Smart WiFi Motion-Activated Relay Module
  ESP8266 Example Code

  Relay  : GPIO16 (ACTIVE HIGH)
  PIR    : GPIO5  (ACTIVE LOW)
  Buzzer : GPIO4  (ACTIVE HIGH)
*/

#define RELAY_PIN   16
#define PIR_PIN     5
#define BUZZER_PIN  4

void setup() {
  // Configure pin modes
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);

  // Ensure outputs are OFF at startup
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(BUZZER_PIN, LOW);

  // Optional: Serial monitor for debugging
  Serial.begin(115200);
  Serial.println("System Initialized");
}

void loop() {
  // Read PIR sensor (LOW = motion detected)
  int pirState = digitalRead(PIR_PIN);

  if (pirState == LOW) {
    // Motion detected
    digitalWrite(RELAY_PIN, HIGH);   // Relay ON
    digitalWrite(BUZZER_PIN, HIGH);  // Buzzer ON

    Serial.println("Motion Detected");
  } else {
    // No motion
    digitalWrite(RELAY_PIN, LOW);    // Relay OFF
    digitalWrite(BUZZER_PIN, LOW);   // Buzzer OFF

    Serial.println("No Motion");
  }

  // Small delay for stability
  delay(100);
}
