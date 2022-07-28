int potPin = 0;

void setup() {
  pinMode(potPin, INPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(potPin));
  delay(1000);
}
