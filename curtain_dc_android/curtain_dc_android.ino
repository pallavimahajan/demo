char varVal;
void setup() {
  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel B pin
  pinMode(8, OUTPUT); //Initiates Brake Channel B pin
  pinMode (7, OUTPUT); // Down LED
  Serial.begin(9600); // Start serial communication at 115200bps
}

// UP @ full speed
void go_up() {
  digitalWrite(13, HIGH); //Establishes UP direction of Channel B
  analogWrite(11, 255); //Spins the motor on Channel B at full speed
  digitalWrite(8, LOW);
}

// DOWN @
void go_down()
{
  digitalWrite(13, LOW); //Establishes DOWN direction of Channel B
  analogWrite(11, 100); //Spins the motor on Channel B at full speed
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
}

void stop_window(){
  digitalWrite(8, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(7, LOW);
}

// Read serial port and perform command
void windowCommand() 
{
  if (Serial.available()) 
  {
    varVal = Serial.read();
  }
  
  if (varVal == 'f') 
  { // UP
    go_up();
  } 
  else if (varVal == 'b') 
  { // DOWN
    go_down();
  }
  else if (varVal == 't') 
  { // Stop
    stop_window();
  }
}

void loop() 
{
  windowCommand();
}
