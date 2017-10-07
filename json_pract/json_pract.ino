#include <ArduinoJson.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

  
void loop() {
 
  Serial.println("—————— -");
 
//  char JSONMessage[] = " {\"name\": \"pallavi\", \"age\": 21,\"city\": [\"belapur\",\"dhule\"],\"student\":{\"frnd\":[\"Ashwini\",\"Pallavi\"],\"classmate\":[\"ash1\",\"ash2\"]}}"; //Original message
  char JSONMessage[] = "{\"res\":[\"ON\",\"OFF\",\"yes\",\"NO\"]}";
  Serial.print("Initial string value: ");
  Serial.println(JSONMessage);
 
  DynamicJsonBuffer JSONBuffer;   //Memory pool
  JsonObject& parsed = JSONBuffer.parseObject(JSONMessage); //Parse message
 
  if (!parsed.success()) {   //Check for errors in parsing
 
    Serial.println("Parsing failed");
    delay(5000);
    return;
 
  }


  const char* on = parsed["res"][0];
  const char* off = parsed["res"][1];
  const char* yes = parsed["res"][2];
//  const char* yes1 = parsed["yes"][2][0];
//  const char* yes2 = parsed["yes"][2][1];
  const char* no = parsed["res"][3];

  Serial.println(on);
  Serial.println(off);
  Serial.println(yes);
//  Serial.print(yes1);
//  Serial.print(yes2);
  Serial.println(no);
   
// 
//  const char* name = parsed["name"]; //Get name value
//  int age = parsed["age"];                //Get value of age
//  const char* city = parsed["city"][0]; //Get city value
//  const char* city1 = parsed["city"][1]; //Get city value
//  const char*  mob=parsed["student"]["frnd"][0];
//  const char* mob1=parsed["student"]["classmate"][0];
//  const char* mob2=parsed["student"]["frnd"][1];
//  const char* mob3=parsed["student"]["classmate"][1];
// 
//  Serial.println(name);
//  Serial.println(age);
//  Serial.println(city);
//  Serial.println(city1);
//  Serial.println(mob);
//  Serial.println(mob1);
//  Serial.println(mob2);
//  Serial.println(mob3);
//   
//  Serial.print("Final string value: ");
 
//  for (int i = 0; i < 40; i++) { //Print the modified string, after parsing
// 
//    Serial.print(JSONMessage[i]);
// 
//  }
 
  Serial.println();
  delay(5000);
 
}
