char varVal;
void setup() {
  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel B pin
  pinMode(8, OUTPUT); //Initiates Brake Channel B pin
  Serial.begin(9600); // Start serial communication at 115200bps
}

void loop(){
  if (Serial.available()) 
  {
    varVal = Serial.read();
  }
  
  if (varVal == 'f') 
  { // UP
//    go_up();
      digitalWrite(13, HIGH);
      digitalWrite(8,LOW);
  } 
  else if (varVal == 'b') 
  { // DOWN
//    go_down();
      digitalWrite(13, LOW);
      digitalWrite(8,HIGH);
  }
  else if (varVal == 't') 
  { // Stop
//    stop_window();
      digitalWrite(8, HIGH);
      digitalWrite(13, LOW);
  }
}
