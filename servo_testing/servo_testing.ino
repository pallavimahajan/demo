//#include <Servo.h> //Servo library
//              
//Servo servo_test;        //initialize a servo object for the connected servo  
//                
////int angle = 0;    
// 
//void setup() 
//{ 
//  servo_test.attach(9);      // attach the signal pin of servo to pin9 of arduino
//} 
//  
//void loop() 
//{ 
//  servo_test.write(90);
//}







//Dc motor example code//

int motorpin1 = 3;                  //define digital output pin no.

int motorpin2 = 4;                  //define digital output pin no.

void setup () {

  pinMode(motorpin1,OUTPUT);        //set pin 3 as output

  pinMode(motorpin2,OUTPUT);        // set pin 4 as output

}
int i=0;

void loop () {
//  for (i=0;i<=10000;i++)
//  {
  digitalWrite(motorpin1,LOW);

  digitalWrite(motorpin2,HIGH);
//  }

  delay(1000);
//  for (i=0;i<=10000;i++)
//  {
//  digitalWrite(motorpin1,HIGH);
//
//  digitalWrite(motorpin2,LOW);
//  }
}


