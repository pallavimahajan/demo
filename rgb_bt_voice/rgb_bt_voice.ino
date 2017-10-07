#include <SoftwareSerial.h>
SoftwareSerial bt(2,3);

#define GREEN 10
#define BLUE 11
#define RED 9
String voice; 
void setup() 
{                                            // put your setup code here, to run once:
  Serial.begin(38400);
  bt.begin(38400);
  
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  
  analogWrite(RED,255); 
  analogWrite(GREEN,255);                    // Since LED must be off in the beginning
  analogWrite(BLUE,255);
}
 
int redVal;
int greenVal;
int blueVal;
 
void loop() {
 
  while (bt.available())   //Check if there is an available byte to read
  {                            
    delay(10);                   //Delay added to make thing stable
    char c = bt.read();      //Conduct a serial read
    if (c == '#') {break;}       //Exit the loop when the # is detected after the word
    voice += c;                  //Shorthand for voice = voice + c
  } 
 
  if (voice.length() > 0) {
    Serial.println(voice);
  //----------Control Multiple Pins/ LEDs----------// 
 
     if(voice == "*red")//                                FOR RED COLOUR OF THE LED 
     {
       analogWrite(RED,0); 
       analogWrite(GREEN,255);
       analogWrite(BLUE,255);
     }  
     else if(voice == "*green")//                              FOR GREEN COLOUR OF THE LED !
     {
       analogWrite(GREEN,0);
       analogWrite(RED,255);
       analogWrite(BLUE,255);
     }
     else if(voice == "*blue")//                                FOR BLUE COLOUR OF THE LED !
     {
       analogWrite(RED,255);
       analogWrite(BLUE,0);
       analogWrite(GREEN,255);
     }
     else if(voice == "*white")//                               FOR WHITE COLOUR OF THE LED !
     {
       analogWrite(RED,0);
       analogWrite(GREEN,0);
       analogWrite(BLUE,0);
     }
     else if(voice == "*good night")//                          FOR TURNING OFF LED !
     {
       analogWrite(RED,255);
       analogWrite(GREEN,255);
       analogWrite(BLUE,255);
     }
  }
  voice="";                                                       //Reset the variable after initiating
  
}
