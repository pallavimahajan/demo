#include <SimpleDHT.h>
#include <ESP8266WiFi.h>
//#include <ArduinoJson.h>

const char* ssid     = "OS3-AP3";
const char* password = "Udt@Punj@b";
String apikey="TILFOHQLNHIHH7YQ";
const char* host = "api.thingspeak.com";
int pinDHT11 = 2;
SimpleDHT11 dht11;

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
  if (dht11.read(pinDHT11, &temperature, &humidity, NULL)) 
  { Serial.print("Read DHT11 failed");
    delay(1000);
  }
  else
  { Serial.println("temperature: ");
    Serial.print(temperature);
    Serial.print(" C\n");
    Serial.println("humidity: ");
    Serial.print(humidity);
    Serial.print("%\n");
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
  String url = "/update?api_key=";
  url+=apikey;
  url+="&field1=";
  url+=String(temperature);
  url+="&field2";
  url+=String(humidity);
  url+="\r\n";
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");

  // Read all the lines of the reply from server and print them to Serial
  
    Serial.println();
    Serial.println("closing connection");

}
