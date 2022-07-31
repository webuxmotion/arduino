int ledpin = 11; // initialize pin 11
int switchPin = 7; // initialize pin 7

boolean lastButton = LOW;
boolean currentButton = LOW;
boolean ledOn = false;

void setup()
{
  pinMode(ledpin, OUTPUT); // set LED pin as “output”
  pinMode(switchPin, INPUT); // set button pin as “input”
  Serial.begin(9600);
}

void loop()
{
  currentButton = debounce(lastButton);

  if (lastButton == LOW && currentButton == HIGH) {
    ledOn = !ledOn;
  }
  
  Serial.println(currentButton);

  lastButton = currentButton;
  digitalWrite(ledpin, ledOn);
}

boolean debounce(boolean last) {
  boolean current = digitalRead(switchPin);

  if (last != current) {
    delay(5);
    current = digitalRead(switchPin);
  }

  return current;
}
