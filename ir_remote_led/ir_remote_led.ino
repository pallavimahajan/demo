/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(6,OUTPUT);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    irrecv.resume(); // Receive the next value
  }
  if (results.value==33480735)      //value for button 0 on ir remote to turn OFF leds
  {
    digitalWrite(2,LOW);
    digitalWrite(4,LOW);
    digitalWrite(6,LOW);
  }
  else if (results.value==33444015)   //value for button 1 on ir remote to turn ON led1
  {
    digitalWrite(2,HIGH);
  }
  else if (results.value==33478695)   //value for button 2 on ir remote to turn ON led2
  {
    digitalWrite(4,HIGH);
  }
  else if (results.value==33486855)   //value for button 3 on ir remote to turn ON led3
  {
    digitalWrite(6,HIGH);
  }
  delay(100);
}
