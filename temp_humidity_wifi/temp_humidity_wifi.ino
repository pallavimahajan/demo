#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#include <ESP8266WiFi.h>
#define DHTPIN 7      //what pin the DHT sensor is connected to
#define DHTTYPE DHT11   // Change to DHT22 if that's what you have
const char* ssid="OS3-AP5";
const char* password="(henna!Expre$$";
WiFiServer server(80);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
delay(10);
pinMode(DHTPIN,OUTPUT);
Serial.println();
Serial.println();
Serial.println("connecting to");
Serial.println(ssid);

WiFi.begin(ssid,password);

while(WiFi.status()!=WL_CONNECTED)
{
  delay(500);
  Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");

server.begin();
Serial.println("server started");

 Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}


void loop() {
  // put your main code here, to run repeatedly:
float h=dht.readHumidity();
float f=dht.readTemperature();

  
  
WiFiClient client=server.available();
if(!client)
{
  return;
}

Serial.println("new client");
while(!client.available())
{
  delay(1);
}

String request=client.readStringUntil('\r');
Serial.println(request);
client.flush();

client.println("HTTP/1.1 200 OK");
client.println("content-Type: text/html");

client.println("");
client.println("<!DOCTYPE HTML>");
client.println("<html>");

client.println("<h1> temperature and humidity");
client.println("<meta http-equiv=\"refresh\" content=\"2\">");


client.println("<br><br>");

//client.println("</h2><h2>ESP8266 humidity:");
//client.println("<a href=\"/hum\"</a>");
//client.println("</h2><h2>ESP8266 humidity:");
//client.println(h);
if(h<=60)
{
  client.println("<font size=\"5\" face=\"Arial\"color=\"green\" >");
  client.println("</h2><h2>ESP8266 humidity:");
  client.println(h);
}
if(h>60)
{
  client.println("<font size=\"5\" face=\"Arial\" color=\"red\">");
  client.println("</h2><h2>ESP8266 humidity:");
  client.println(h);
}
client.println("<br><br>");

if(f<26)
{
client.println("<font size=\"5\" face=\"Arial\"color=\"green\">");
//client.println(("<font size=\"5\" face=\"Arial\"text=\"green\">");
client.println("</h2><h2> temperature:");
client.println(f);
}
if(f>=26)
{
  client.println("<font size=\"5\" face=\"calibri\"color=\"red\">");
  client.println("</h2><h2> temperature:");
  client.println(f);
}
client.println("</html>");
delay(1);
Serial.println("client disconnected");
Serial.println("");

}
