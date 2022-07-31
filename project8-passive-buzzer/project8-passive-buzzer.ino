/*
  keyestudio super learning kit
  Project 8
  Passive Buzzer
  http//www.keyestudio.com
*/
int buzzer = 8; // select digital IO pin for the buzzer

void setup()
{
  pinMode(buzzer, OUTPUT); // set digital IO pin pattern, OUTPUT to be output
}

void loop() { 
  
  
  while (1)
  {
    soundShort();
    delay(1998);

    soundShort();
    delay(1998);

    soundShort();
    delay(1998);

    soundLong();
    delay(1898);
  }
}

void soundShort() {
  unsigned char i;
  
  for (i = 0; i < 1; i++) {
      digitalWrite(buzzer, HIGH); // sound
      delay(5);
      digitalWrite(buzzer, LOW); //not sound
      delay(5);
    }
}


void soundLong() {
  unsigned char i;
  
  for (i = 0; i < 30; i++) {
      digitalWrite(buzzer, HIGH); // sound
      delay(5);
      digitalWrite(buzzer, LOW); //not sound
      delay(5);
    }
}
//////////////////////////////////////////////////////////////////
