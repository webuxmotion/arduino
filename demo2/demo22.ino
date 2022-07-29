int switchPin = 8;
int ledPin = 13;
boolean lastButton = LOW;
boolean currentButton = LOW;
boolean ledOn = false;

void setup() {
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

boolean debounce(boolean last) {
  boolean current = digitalRead(switchPin);
  if (last != current) {
    delay(5);
    current = digitalRead(switchPin);
  }
  return current;
}

void loop() {
  currentButton = debounce(lastButton);
  if (digitalRead(switchPin) == HIGH && lastButton == LOW) {
    ledOn = !ledOn;
    lastButton = HIGH;
  } else {
    lastButton = digitalRead(switchPin);
  }

  digitalWrite(ledPin, ledOn);
}
