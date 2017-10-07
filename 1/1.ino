//#include <ArduinoJson.h>

/*
 *  This sketch sends data via HTTP GET requests to data.sparkfun.com service.
 *
 *  You need to get streamId and privateKey at data.sparkfun.com and paste them
 *  below. Or just customize this script to talk to other HTTP servers.
 *
 */

#include <ESP8266WiFi.h>

const char* ssid     = "Ashwini";
const char* password = "12345678";

//const char* ssid     = "OS3-AP1";
//const char* password = "(henna!Expre$$";

const char* host = "10.0.31.2";

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
  String url = "/api/index.php?a=res";
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");

  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  } 
     // Read all the lines of the reply from server and print them to Serial
 while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

//   
// StaticJsonBuffer<200> jsonBuffer;
// JsonObject& root = jsonBuffer.parseObject(line);
// int data = root["res"];  
// Serial.println();
// Serial.print(data);
//  }
 Serial.println();
 Serial.println("closing connection");  
 }
       



