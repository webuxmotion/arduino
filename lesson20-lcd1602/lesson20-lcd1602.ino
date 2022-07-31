/*
  keyestudio super learning kit
  Project 20.1
  LCD1602
  http//www.keyestudio.com
*/
int potPin = 0;
int DI = 12;
int RW = 11;
int DB[] = {3, 4, 5, 6, 7, 8, 9, 10};// use array to select pin for bus
int Enable = 2;

int Relay = A0;
byte sensorPin = A1;

void LcdCommandWrite(int value) {

  // define all pins
  int i = 0;
  for (i = DB[0]; i <= DI; i++) // assign value for bus
  {
    digitalWrite(i, value & 01); // for 1602 LCD, it uses D7-D0( not D0-D7) for signal identification; here, it’s used for signal inversion.
    value >>= 1;
  }
  digitalWrite(Enable, LOW);
  delayMicroseconds(1);
  digitalWrite(Enable, HIGH);
  delayMicroseconds(1);  // wait for 1ms
  digitalWrite(Enable, LOW);
  delayMicroseconds(1);  // wait for 1ms
}

void LcdDataWrite(int value) {
  // initialize all pins
  int i = 0;
  digitalWrite(DI, HIGH);
  digitalWrite(RW, LOW);
  for (i = DB[0]; i <= DB[7]; i++) {
    digitalWrite(i, value & 01);

    value >>= 1;
  }
  digitalWrite(Enable, LOW);
  delayMicroseconds(1);
  digitalWrite(Enable, HIGH);
  delayMicroseconds(1);
  digitalWrite(Enable, LOW);
  delayMicroseconds(1);  // wait for 1ms
}

void setup (void) {
  Serial.begin(9600);
  pinMode(Relay, OUTPUT);
  pinMode(sensorPin, INPUT);
  int i = 0;
  for (i = Enable; i <= DI; i++) {
    pinMode(i, OUTPUT);
  }
  delay(100);
  // initialize LCD after a brief pause
  // for LCD control
  LcdCommandWrite(0x38);  // select as 8-bit interface, 2-line display, 5x7 character size
  delay(64);
  LcdCommandWrite(0x38);  // select as 8-bit interface, 2-line display, 5x7 character size
  delay(50);
  LcdCommandWrite(0x38);  // select as 8-bit interface, 2-line display, 5x7 character size
  delay(20);
  LcdCommandWrite(0x06);  // set input mode
  // auto-increment, no display of shifting
  delay(20);
  LcdCommandWrite(0x0E);  // display setup
  // turn on the monitor, cursor on, no flickering
  delay(20);
  LcdCommandWrite(0x01);  // clear the scree, cursor position returns to 0
  delay(100);
  LcdCommandWrite(0x80);  //  display setup
  //  turn on the monitor, cursor on, no flickering

  delay(20);
}

void loop (void) {
  byte state = digitalRead(sensorPin);

  if (state == 1) {
    digitalWrite(Relay, HIGH);

    writeOtherText();
  } else {
    digitalWrite(Relay, LOW);
  }
}

void writeOtherText() {
  LcdCommandWrite(0x01);  // clear the screen, cursor returns to 0
  delay(10);
  LcdDataWrite('S');
  LcdDataWrite('l');
  LcdDataWrite('a');
  LcdDataWrite('v');
  LcdDataWrite('a');
  LcdDataWrite(' ');
  LcdDataWrite('U');
  LcdDataWrite('k');
  LcdDataWrite('r');
  LcdDataWrite('a');
  LcdDataWrite('i');
  LcdDataWrite('n');
  LcdDataWrite('i');
  delay(2000);

  LcdCommandWrite(0x01); // clear the screen, cursor returns to 0
  delay(10); 
  
  LcdDataWrite('r');
  LcdDataWrite('u');
  LcdDataWrite('s');
  LcdDataWrite('n');
  LcdDataWrite('i');
  LcdDataWrite(' ');
  LcdDataWrite('p');
  LcdDataWrite('i');
  LcdDataWrite('z');
  LcdDataWrite('d');
  LcdDataWrite('a');
  delay(4000);

  LcdCommandWrite(0x01); // clear the screen, cursor returns to 0
  
  delay(10);
}
//////////////////////////////////////////////////////////
