#include <SimpleDHT.h>

// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11;

#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10
int err;
byte temperature;
byte humidity;
char rx_byte=0;
void setup() {
//  Serial.begin(115200);

    Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}
void loop() {
  if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();
  
    switch (rx_byte) {
    case '1':
        // start working...
    Serial.println("=================================");
    Serial.println("Sample DHT11...");
  
  // read without samples.
    temperature = 0;
    humidity = 0;
     err = SimpleDHTErrSuccess;
    if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
      Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
      return;
    }
  
    Serial.print("Sample OK: ");
    Serial.print((int)temperature); Serial.print(" *C, "); 
    Serial.print((int)humidity); Serial.println(" H");
  
  // DHT11 sampling rate is 1HZ.
    delay(1500);
    break;

    case '2':
        long duration, distance;
    digitalWrite(trigPin, LOW);  // Added this line
    delayMicroseconds(2); // Added this line
    digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
    delayMicroseconds(10); // Added this line
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    if (distance < 4) {  // This is where the LED On/Off happens
      digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
      digitalWrite(led2,LOW);
    }
    else {
      digitalWrite(led,LOW);
      digitalWrite(led2,HIGH);
    }
    if (distance >= 200 || distance <= 0){
      Serial.println("Out of range");
    } 
    else {
      Serial.print(distance);
      Serial.println(" cm");
    }
    delay(500);
      break;
      
   case '3':
        Serial.println("------- MENU -------");
        Serial.println("1. temp and humidity readings.");
        Serial.println("2. object detecting.");
        Serial.println("3. This menu.");
        Serial.println("--------------------");
      break;
      
   default:
        Serial.println("Invalid option");
      break;
    } // end: switch (rx_byte)
  } // end: if (Serial.available() > 0)
}
