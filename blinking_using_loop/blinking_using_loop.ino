
void setup(){
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop(){
  for(int i=0;i<=5;i++)
  {
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
  }
  
  for(int i=0;i<=5;i++)
  {
  digitalWrite(12,HIGH);
  delay(500);
  digitalWrite(12,LOW);
  delay(500);
  }
}
