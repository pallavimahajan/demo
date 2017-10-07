#include<Servo.h>

Servo servo;
int accelero;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  Serial.setTimeout(5);
  servo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    accelero=Serial.parseInt();
    if(accelero>-95 && accelero<95)
    {
      accelero=map(accelero,-95,95,0,180);
      servo.write(accelero);
    }
  }
}
