int redpin = 11;
int greenpin = 9;
int bluepin = 10;

int val;
void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  Serial.begin(9600);
}
void loop() 
{
  for(val=0; val<255; val++)
  {
   analogWrite(11, val);
   analogWrite(9, 1);
   analogWrite(10, 1);
   
   delay(3); 
  }
for(val=255; val>0; val--)
  {
   analogWrite(11, val);
   analogWrite(9, 1);
   analogWrite(10, 1);
   delay(3); 
  }

 Serial.println(val, DEC);
}
