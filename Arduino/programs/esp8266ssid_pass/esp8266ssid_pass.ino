
#include <ESP8266WiFi.h>

const char* ssid="JioFi_100D24B";  //Service set identifier
const char* password = "6mxmksisbj"; 

int ledPin = 13;//Node mcu pin D7
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);


  Serial.println();
  Serial.print("Wifi connecting to ");
  Serial.println( ssid );

  WiFi.begin(ssid,password);

  while( WiFi.status() != WL_CONNECTED ){
      delay(500);
      Serial.print(".");        
  }
  server.begin();
  digitalWrite( ledPin , HIGH);
  Serial.println();

  Serial.println("Wifi Connected Success!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP() );

}

void loop() {
  // put your main code here, to run repeatedly:
  //Check if client is connected or not
WiFiClient client = server.available ();
if (!client) {
  return;
  }
  //Wait for input by client .
  Serial.println("new client ");
  while(!client.available()){
    delay(1);
    }
// Read the first line of the request 
 String request = client.readStringUntil('\r');
 Serial.println(request);
 client.flush();
 // Match the request 
 int value = LOW ;
 if (request.indexOf("/LED=ON") != -1 ) {
  digitalWrite(ledPin,HIGH);
  value = HIGH;
 }
 if (request.indexOf("/LED=OFF") != -1 ) {
  digitalWrite(ledPin , LOW ) ;
  value = LOW ; 
  }

  //Set ledPin according to the request .
  //digitalWrite(ledPin ,value);

  // Returning the response 
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

  client.print("Led pin is now : ");

  if (value == HIGH ) {
    client.print("ON");
    }
    else {
      client.print ("OFF");
      }
      client.println("<br><br>");
      client.println("<a href=\"/LED=ON\"\"><button>Turn On </button></a>");
      client.println("<a href=\"/LED=OFF\"\"><button>Turn Off </button></a>");
      client.println("</html>");

      delay(1);
      Serial.println("Client disconnected");
      Serial.println("");
}
