

#include <ESP8266WiFi.h>
//#include <ArduinoJson.h>

    const char* ssid     = "Ashwini";
    const char* password = "12345678";

   
//    const char* ssid     = "OS3-AP3";
//    const char* password = "Udt@Punj@b";
    
    const char* host = "iot-ashu.000webhostapp.com";

    void setup() {
      Serial.begin(115200);
      delay(100);

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

      //-----------------------
      delay(5000);
    }

    void loop(){
      Serial.print("connecting to ");
      Serial.println(host);

      // Use WiFiClient class to create TCP connections
      WiFiClient client;
      const int httpPort = 8095;
      if (!client.connect(host, httpPort)) {
        Serial.println("connection failed");
        return;
      }

      // We now create a URI for the request
      String url = "/api/index.php?a=res";
      Serial.print("Requesting URL: ");
      Serial.println(url);

      // This will send the request to the server
      client.print("GET " + url + " HTTP/1.1\r\n" +
                   "Host: " + host + "\r\n" +
                   "ApiCode: 8273\r\n" +
                   "Content-Type: application/json\r\n" + 
                   "Connection: close\r\n\r\n");
      delay(500);
       char c[1024];
      // Read all the lines of the reply from server and print them to Serial
       while(client.available()){
          c[0] = client.read();

      //Serial.print(c);

     Serial.print(c);
     }
//       StaticJsonBuffer<200> jsonBuffer;
//       JsonObject& root = jsonBuffer.parseObject(c);
//      int data = root["lowVersion"];  
//      Serial.println();
//         Serial.print(data);

      Serial.println();
      Serial.println("closing connection");  
      }
