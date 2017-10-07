#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

const char* ssid     = "Ashwini";
const char* password = "12345678";
const char* host = "iot-ashu.000webhostapp.com";
int i1;
int i2;
String line;

void setup() {
  Serial.begin(115200);
  delay(10);

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
    Serial.println("client connected");

    client.print("GET /index.php?a=res HTTP/1.1\r\n");
    client.println("Host: iot-ashu.000webhostapp.com \r\n");
    client.println("Connection: close\r\n\r\n");
               
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
    line += client.readStringUntil('\r');
  }
     Serial.println("----------------------------------------------------------------------------------");
     Serial.print(line);
       
     int i1 = line.indexOf("{");
     int i2 = line.lastIndexOf("}");
     Serial.print("INDEX OF '{' :");
     Serial.println(i1);
     Serial.print("INDEX OF '}' :");
     Serial.println(i2);
     String res = line.substring(i1, i2+1);
     
     Serial.println("---------------------------------------------------------------------------------");
     Serial.print("JSON OUTPUT :");
     Serial.println(res);

     StaticJsonBuffer<200> JsonBuffer;
     JsonObject& root = JsonBuffer.parseObject(res);
     if (root.success())
        {
          Serial.println("parseObject() success");
          delay(1000); 
        }
     Serial.print("----------------------------------------------------------------------------------");
     const char* Name    = root["res"][2]["yes"][1];
     Serial.println("OUTPUT IS :");
     Serial.println(Name);
     Serial.println("-----------------------------------------------------------------------------------");

     Serial.println("closing connection");
     Serial.println("-------------------------------------------------------------------------------------");
}
