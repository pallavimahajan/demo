#include <SoftwareSerial.h>
/* Create object named bt of the class SoftwareSerial */
SoftwareSerial bt(2,3); // RX, TX
#define ledPin 13
char state = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
//  digitalWrite(ledPin, LOW);
  Serial.begin(38400); /* Define baud rate for serial communication */
  bt.begin(38400);     /* Define baud rate for software serial communication */
  
}
void loop() {
  if(bt.available() > 0){ // Checks whether data is comming from the serial port
    state = bt.read();
    Serial.println(state); // Reads the data from the serial port
 }
 if (state == '0') 
 {
  digitalWrite(ledPin, LOW); // Turn LED OFF
  Serial.println("LED: OFF"); // Send back, to the phone, the String "LED: OFF"
  bt.println("LED: OFF");
  state = "";
 }
 else if (state == '1') {
  digitalWrite(ledPin, HIGH); // Turn LED OFF
  Serial.println("LED: ON");  // Send back, to the phone, the String "LED: ON"
  bt.println("LED: ON");
  state = "";
 } 
}

 
