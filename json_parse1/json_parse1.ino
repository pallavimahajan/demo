#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

const char* ssid     = "Ashwini";
const char* password = "12345678";

//const char* ssid     = "OS3-AP3";
//const char* password = "Udt@Punj@b";

const char* host = "iot-ashu.000webhostapp.com";

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
  String url = "/index.php?a=res";
  
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
  
        if (root.success())
        {
          Serial.println("parseObject() success");
          delay(1000);
          
        }
        
        const char* Name    = root["res"][0];
        Serial.println(Name);
        const char* Name1    = root["res"][1];
        Serial.println(Name1);
        const char* Name2    = root["res"][2]["yes"][0];
        Serial.println(Name2);
        const char* Name3    = root["res"][3];
        Serial.println(Name3);
        
        
    }
    Serial.println();
    Serial.println("closing connection");
}
