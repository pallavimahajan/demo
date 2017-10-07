#include <ArduinoJson.h>

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
char json[] = "{\"name\":\"pallavi\",\"age\":21,\"addr\":[\"shirpur\",\"belapur\"]}";

//,\"mob\":[{\"type\":\"home\",\"no\":8857801737},{\"type\":\"office\",\"no\":7957801737}]

//
// Step 1: Reserve memory space
//
StaticJsonBuffer<200> jsonBuffer;

//
// Step 2: Deserialize the JSON string
//
JsonObject& root = jsonBuffer.parseObject(json);

if (!root.success())
{
  Serial.println("parseObject() failed");
  return;
}

//
// Step 3: Retrieve the values
//
const char* name    = root["name"];
int        age      = root["age"];
const char* addr  = root["addr"][0];
const char* addr1 = root["addr"][1];
//const char* mob =root

Serial.println(name);
Serial.println(age);
Serial.println(addr);
Serial.println(addr1);
}
