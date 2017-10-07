#include<ESP8266WiFi.h>
#include<ESP8266HTTPClient.h>

const char* ssid="";
const char* password="";

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
WiFi.begin(ssid,password);

while(WiFi.status != WL_CONNECTED){
  delay(1000);
  Serial.print("Connecting...");
}
}

void loop() {
  // put your main code here, to run repeatedly:
if (WiFi.status)


}
