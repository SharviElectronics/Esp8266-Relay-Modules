#define RLY_1 16
#define RLY_2 14
#define RLY_3 12
#define RLY_4 13
// Variables will change:
int ledState = LOW; // ledState used to set the LED
unsigned long previousMillis = 0; // will store last time LED was updated
// constants won't change:
const long interval = 1000; // interval at which to blink (milliseconds)
void setup() 
{
  // set the digital pin as output:
  pinMode(RLY_1, OUTPUT);
  pinMode(RLY_2, OUTPUT);
  pinMode(RLY_3, OUTPUT);
  pinMode(RLY_4, OUTPUT);
}
void loop() 
{
  unsigned long currentMillis = millis(); 
  if (currentMillis - previousMillis >= interval) // save the last time you blinked the LED
  {
    previousMillis = currentMillis;
    if (ledState == LOW)
    {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    // set the LED with the ledState of the variable:
    digitalWrite(RLY_1, ledState);
    digitalWrite(RLY_2, ledState);
    digitalWrite(RLY_3, ledState);
    digitalWrite(RLY_4, ledState);
  }
} 
