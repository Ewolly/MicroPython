 #include <ESP8266WiFi.h>
 
const char* ssid = "AndroidAP";//type your ssid
const char* password = "12345678";//type your password
 
int ledPin = 1; // GPIO2 of ESP8266
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);
 
 
//  pinMode(ledPin, OUTPUT);
//  digitalWrite(ledPin, LOW);
   
  // Connect to WiFi network
  
  WiFi.begin(ssid, password);
   
  // Start the server
  server.begin();  
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
   
  // Wait until the client sends some data
  while(!client.available()){
    delay(1);
  }

  int i = 0; 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  for (i=0; i < 10000; ++i){
      client.print(request);             //change this to spaaam
  }
  client.flush();
}
  // Match the request
 
/*  int value = LOW;
  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(ledPin, HIGH);
    value = HIGH;
  } 
  if (request.indexOf("/LED=OFF") != -1){
    digitalWrite(ledPin, LOW);
    value = LOW;
  }
 
// Set ledPin according to the request
//digitalWrite(ledPin, value);
   
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
   
  client.print("Led pin is now: ");
   
  if(value == HIGH) {
    client.print("On");  
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("Click <a href=\"/LED=ON\">here</a> turn the LED on pin 2 OFF<br>");
  client.println("Click <a href=\"/LED=OFF\">here</a> turn the LED on pin 2 ON<br>");
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
*/
