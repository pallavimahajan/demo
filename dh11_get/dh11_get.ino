
#include <ESP8266WiFi.h>
#include <SimpleDHT.h>
#include <ArduinoJson.h>

//https://thingspeak.com/channels/329302/feed.json
const char* ssid     = "Ashwini";
const char* password = "12345678";
//const char* ssid     = "OS3-AP3";                
//const char* password = "Udt@Punj@b";
const char* writeAPIKey = "PS3X3PVRKT66DQCK";


const char* host = "api.thingspeak.com";   

int pinDHT11 = 2;
SimpleDHT11 dht11;
int i1 ;
int i2;

void setup() {
  Serial.begin(115200);
  delay(10);
  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
 Serial.println("IP address: ");
 Serial.println(WiFi.localIP());
}

void loop() {
 
 byte temperature = 0;
  byte humidity = 0;
 if (dht11.read(pinDHT11, &temperature, &humidity, NULL)) {
   Serial.print("Read DHT11 failed.");
   delay(500);
    
  } 
  
  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  // We now create a URI for the request
//String url = "/update?api_key=";
  
 String url = "/update?api_key=";    //to see json(sensor) data
    
  url+=writeAPIKey;
  url+="&field1=";
  url+=String(temperature);
  url+="&field2=";
  url+=String(humidity);
  url+="\r\n";
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
               
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }


  
  // Read all the lines of the reply from server and print them to Serial

  String line;
  while(client.available())
 {
   line += client.readStringUntil('\r');
 }
}

