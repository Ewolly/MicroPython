#include <ESP8266WiFi.h>

const char *ssid = "AndroidAP";//type your ssid
const char *password = "12345678";//type your password
 
WiFiServer server(80);

char *response_buffer;

void setup() {
  // Connect to WiFi network
  
  WiFi.begin(ssid, password);
   
  // Start the server
  server.begin();

  response_buffer = (char *)malloc(sizeof(char)*3000);
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  // client.setNoDelay(1);
  // Wait until the client sends some data
  while(!client.available()){
    delay(1);
  }

  int i = 0; 
  // Read the first line of the request
  byte n = client.readBytesUntil('\r', response_buffer, 2999);
  response_buffer[n] = '\0';
  
  for (i=0; i < 10000; ++i){
      client.print(response_buffer);
  }
  client.flush();
}
