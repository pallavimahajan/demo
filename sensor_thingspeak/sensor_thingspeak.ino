


#include <ESP8266WiFi.h>
#include <SimpleDHT.h>

int pinDHT11 = 2;
SimpleDHT11 dht11;
String apikey="TILFOHQLNHIHH7YQ";
const char* ssid="OS3-AP3";
const char* password="Udt@Punj@b";
int duration= 5 ;

const char* server="api.thingspeak.com";
WiFiClient client;
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid,password);
  Serial.println();
  Serial.println();
  Serial.println("connecting to ");
  Serial.println(ssid);
  while (WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("wifi connected");
}

void loop() {

  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  if (dht11.read(pinDHT11, &temperature, &humidity, NULL)) {
    Serial.print("Read DHT11 failed, err="); delay(1000);
  }
//  
//  Serial.print("Sample OK: ");
//  Serial.print((int)temperature); Serial.print(" *C, "); 
//  Serial.print((int)humidity); Serial.println(" H");
//  
//  // DHT11 sampling rate is 1HZ.
//  delay(1500);
  if (client.connect(server,80)){
    String postStr=apikey;
    postStr+="&temp=";
    postStr+=String(temperature);
    postStr+="&humidity=";
    postStr+=String(humidity);
    postStr+="\r\n";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: "+ apikey +"\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print(postStr.length());
    client.print("\n\n");
    client.print(postStr);

    Serial.print("temp : ");
    Serial.print(temperature);
    Serial.print("humidity : ");
    Serial.print(humidity);
    Serial.println("% send to thingspaek");
  }
  client.stop();

  Serial.println("waiting......");
  delay(duration*1000);



}


