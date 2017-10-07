int ledPin = 13;
char incomingByte;

void setup() {
Serial.begin(19200);
pinMode(13, OUTPUT);
}

void loop(){
if (Serial.available() > 0) {
incomingByte = Serial.read();
if (incomingByte == 'A') {
digitalWrite(13, HIGH);
}
if (incomingByte == 'B') {
digitalWrite(13, LOW);
}
}
}
