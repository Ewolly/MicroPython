#include <ESP8266WiFi.h>
#include <WiFiClient.h> 

WiFiServer server(80);

void setup()
{
  delay(10000);
  Serial.begin(115200);
  Serial.println();

  Serial.print("Setting soft-AP ... ");
  WiFi.softAP("ESPAP", "qwerty123");

  server.begin();  
}

void loop()
{
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  client.setNoDelay(1);
  // Wait until the client sends some data
  while(!client.available()){
    delay(1);
  }
  client.setNoDelay(1);
  int i = 0; 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  for (i=0; i < 10000; ++i){
      client.print(request);
  }
  client.flush();
}
