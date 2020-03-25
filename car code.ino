#include <SoftwareSerial.h>

SoftwareSerial BT(10,11); //TX, RX respetively
String readdata;

void setup() {
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(2, OUTPUT);  //in1
  pinMode(4, OUTPUT);  //in2
  pinMode(5, OUTPUT);  //in3
  pinMode(6, OUTPUT);   //in4
//  pinMode(3, OUTPUT);
//  pinMode(9,OUTPUT);
}
//-----------------------------------------------------------------------// 
void loop() {
  while (BT.available()){  //Check if there is an available byte to read
    
  delay(10); //Delay added to make thing stable
  char c = BT.read(); //Conduct a serial read
  readdata += c; //build the string- "forward", "reverse", "left" and "right"
  } 
  if (readdata.length() > 0) {
    Serial.println(readdata);

  if(readdata == "forward")
  {
    digitalWrite(2, HIGH);
    digitalWrite (4, LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
 //   analogWrite(3,175);
  //  analogWrite(9,175);
  //  delay(100);
  }

  else if(readdata == "reverse")
  {
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6,HIGH);
 //   analogWrite(3,175);
//   analogWrite(9,175);
  //  delay(100);
  }

  else if (readdata == "right")
  {
    digitalWrite (2,HIGH);
    digitalWrite (4,LOW);
    digitalWrite (5,LOW);
    digitalWrite (6,HIGH);
   // analogWrite(3,200);
   // analogWrite(9,200);
  //  delay (100);
   
  }

 else if ( readdata == "left")
 {
   digitalWrite (2, LOW);
   digitalWrite (4, HIGH);
   digitalWrite (5, HIGH);
   digitalWrite (6, LOW);
   //analogWrite(3,200);
  // analogWrite(9,200);
  // delay (100);
 }

 else if (readdata == "stop")
 {
   digitalWrite (2, LOW);
   digitalWrite (4, LOW);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   //delay (100);
 }

  


readdata="";}} //Reset the variable
