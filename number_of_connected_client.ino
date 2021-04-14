#include <ESP8266WiFi.h>
long rssi =0;
void setup()
{
  Serial.begin(115200);
  Serial.println();
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.print("Setting soft-AP ... ");
  boolean result = WiFi.softAP("Client", "password");
  if(result == true)
  {
    Serial.println("Ready");
  }
  else
  {
    Serial.println("Failed!");
  }
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
  WiFi.begin("server1", "qwertyuiop");
}

void loop()
{
   while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    digitalWrite(LED_BUILTIN,HIGH);
    Serial.print(".");
  }
  
  if(WiFi.status() == WL_CONNECTED){
   rssi = WiFi.RSSI();
  Serial.print("RSSI: ");
  Serial .println(rssi);
    if(rssi>-100){
      digitalWrite(LED_BUILTIN,LOW);
      Serial.println("rssi is less than -100");
      delay(1000);
      }else{
        digitalWrite(LED_BUILTIN,HIGH);
        }
    }
}
