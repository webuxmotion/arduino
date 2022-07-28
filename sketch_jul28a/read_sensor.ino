int sensePin = 0;

void setup() {
  analogReference(DEFAULT);

  Serial.begin(9600);
}

void loop() {
  Serial.pringln(analogRead(sensePin));
  delay(500);
}
