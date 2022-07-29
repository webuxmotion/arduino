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

void LcdCommandWrite(int value) {
  
// define all pins
int i = 0;
for (i=DB[0]; i <= DI; i++) // assign value for bus
{
   digitalWrite(i,value & 01);// for 1602 LCD, it uses D7-D0( not D0-D7) for signal identification; here, it’s used for signal inversion. 
   value >>= 1;
}
digitalWrite(Enable,LOW);
delayMicroseconds(1);
digitalWrite(Enable,HIGH);
delayMicroseconds(1);  // wait for 1ms
digitalWrite(Enable,LOW);
delayMicroseconds(1);  // wait for 1ms
}

void LcdDataWrite(int value) {
// initialize all pins
int i = 0;
digitalWrite(DI, HIGH);
digitalWrite(RW, LOW);
for (i=DB[0]; i <= DB[7]; i++) {
   digitalWrite(i,value & 01);
   
   value >>= 1;
}
digitalWrite(Enable,LOW);
delayMicroseconds(1);
digitalWrite(Enable,HIGH);
delayMicroseconds(1);
digitalWrite(Enable,LOW);
delayMicroseconds(1);  // wait for 1ms
}

void setup (void) {
  Serial.begin(9600);
  int i = 0;
  for (i=Enable; i <= DI; i++) {
     pinMode(i,OUTPUT);
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
  LcdCommandWrite(0x01);  // clear the scree, cursor position returns to 0  
  delay(10); 
  LcdCommandWrite(0x80+4); 
  delay(10);                     
  // write in welcome message 

//  int val;// define variable
//  int dat;// define variable
//  val=analogRead(0);// read the analog value of the sensor and assign it to val
//  dat=(125*val)>>8;// temperature calculation formula
//  Serial.println(dat);
//  
//  
//  LcdDataWrite('0' + dat / 10);
//  LcdDataWrite('0' + dat % 10);
  LcdDataWrite('C');
  
  //delay(10);
  //LcdCommandWrite(0xc0+1);  // set cursor position at second line, second position
  
//  writeOtherText();
  
  delay(500);
}

void writeOtherText() {
  delay(1000);
  LcdCommandWrite(0x01);  // clear the screen, cursor returns to 0  
  delay(10);
  LcdDataWrite('I');
  LcdDataWrite(' ');
  LcdDataWrite('a');
  LcdDataWrite('m');
  LcdDataWrite(' ');
  LcdDataWrite('h');
  LcdDataWrite('u');
  LcdDataWrite('n');
  LcdDataWrite('t');
  LcdDataWrite('e');
  LcdDataWrite('r');
  delay(1000);
  LcdCommandWrite(0x02); // set mode as new characters replay old ones, where there is no new ones remain the same
  delay(10);
  LcdCommandWrite(0x80+5); // set cursor position at first line, sixth position
  delay(10);  
  LcdDataWrite('t');
  LcdDataWrite('h');
  LcdDataWrite('e');
  LcdDataWrite(' ');
  LcdDataWrite('w');
  LcdDataWrite('o');
  LcdDataWrite('r');
  LcdDataWrite('l');
  LcdDataWrite('d');
}
//////////////////////////////////////////////////////////
