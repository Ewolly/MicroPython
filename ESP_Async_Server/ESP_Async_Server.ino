#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <async_config.h>
#include <ESPAsyncTCP.h>
#include <tcp_axtls.h>

#define UNUSED_PARAMETER(x) (x)

const char *ssid = "AndroidAP";//type your ssid
const char *password = "12345678";//type your password

void clientConnected(void* _u, AsyncClient* client)
{
  Serial.print("Speed tests are great");
}

// std::function<void(void*, AsyncClient*, void *data, size_t len)

void dataRecieved(void* _u, AsyncClient* client, void *data, size_t len)
{
  UNUSED_PARAMETER(_u);
  UNUSED_PARAMETER(len);
  int i = 0;
  for (i=0; i < 10000; ++i){
    
  }
      client->write((const char*)data);
}


void setup() {
  delay(5000);
  // put your setup code here, to run once:
  WiFi.begin(ssid,password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
      return;
  }
  Serial.begin(115200);
  AsyncServer myAsync = AsyncServer(80);
  myAsync.begin();
  
  // myAsync.onClient(&clientConnected, NULL);
  // myAsync.setNoDelay(1);
}


void loop() {

}
