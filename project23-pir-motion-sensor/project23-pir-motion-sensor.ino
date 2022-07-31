#include <Servo.h>
Servo myservo;

byte sensorPin = 3;
byte indicator = 13;
byte ledPin = 10;
boolean servoInProcess = false;


void setup()
{
  pinMode(sensorPin,INPUT);
  pinMode(indicator,OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  myservo.attach(9);
}
void loop()
{
  byte state = digitalRead(sensorPin);
  digitalWrite(indicator,state);
  digitalWrite(ledPin,  state);
  
  
  if(state == 1) {
    Serial.println("Somebody is in this area!");
    if (servoInProcess == false) {
      servoInProcess == true;
      runServo();
    }
    servoInProcess == false;
  }
  else if(state == 0)Serial.println("No one!");
  delay(100);
}

void runServo() {
  myservo.write(10);
  delay(100);
  myservo.write(0);
  delay(5000);
}
