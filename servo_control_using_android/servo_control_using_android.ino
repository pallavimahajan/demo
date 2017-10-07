#include <Servo.h>
#include <SoftwareSerial.h>
Servo myservo;
SoftwareSerial bt(10,11); //BTtx,BTrx


void setup() {
  // put your setup code here, to run once:
myservo.attach(9);
Serial.begin(38400);
bt.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
if(bt.available()>0)
{
  int tosend=bt.read();
  Serial.println(tosend);
  myservo.write(tosend);
}
}
