#define RLY_1 16
#define RLY_2 14
#define RLY_3 12
#define RLY_4 13
#define RLY_5 15
#define RLY_6 10
#define RLY_7 4
#define RLY_8 5
// Variables will change:
int ledState = LOW; // ledState used to set the LED
// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
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
  pinMode(RLY_5, OUTPUT);
  pinMode(RLY_6, OUTPUT);
  pinMode(RLY_7, OUTPUT);
  pinMode(RLY_8, OUTPUT);
}
void loop()
{
  // here is where you'd put code that needs to be running all the time.
  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    // if the LED is off turn it on and vice-versa:
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
    digitalWrite(RLY_5, ledState);
    digitalWrite(RLY_6, ledState);
    digitalWrite(RLY_7, ledState);
    digitalWrite(RLY_8, ledState);
  }
}
