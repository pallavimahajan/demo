#include <ESP8266WiFi.h>
#include <SimpleDHT.h>
#include <ArduinoJson.h>

const char* ssid     = "Ashwini";
const char* password = "12345678";

//const char* ssid     = "OS3-AP3";
//const char* password = "Udt@Punj@b";

const char* host = "iot-ashu.000webhostapp.com";
// 
//const char* ssid = "OS3-AP3";//type your ssid
//const char* password = "Chenna!Expre$$";//type your password
// 
//int ledPin = 9; // GPIO2 of ESP8266
WiFiServer server(80);//Service Port


int pinDHT11 = 2;
SimpleDHT11 dht11;
byte temprature = 0;
byte humidity = 0;

void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(pinDHT11, OUTPUT);
  // Connect to WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
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
       Serial.println("Read DHT11 failed.");
    }
  else{
       Serial.println("Sample OK: ");
       Serial.println((int)temperature); Serial.print(" *C, "); 
       Serial.println((int)humidity); Serial.println(" %");
  
        // DHT11 sampling rate is 1HZ.
       delay(1000);
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
  String url = "/weather.php?data1=45&data2=12";
  
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
  while(client.available())
    {
      String line = client.readStringUntil('\r');
      Serial.print(line);
      StaticJsonBuffer<300> jsonBuffer;
      JsonObject& root = jsonBuffer.parseObject(line);

      if(root.success()){
        Serial.println("parseObject() success");
        delay(100);
      }
    const char* name1=root["data1"];
    Serial.println("name1");
    const char* name2=root["data2"];
    Serial.println("name2");
    }    
    Serial.println();
    Serial.println("closing connection");
}
 
