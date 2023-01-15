#include <dht.h>

int ledPin = 6 ;
int ledPin2 = 7 ;

#define dataPin 8
dht DHT ;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
   pinMode(ledPin2,OUTPUT);
}

void loop() {
int readData = DHT.read11(dataPin);
float t = DHT.temperature ; 
float h = DHT.humidity ; 
Serial.print("TEMPERATURE = " );
Serial.print(t);
Serial.println(" C " );
Serial.print("Humidity = ") ;
Serial.print(h);
Serial.println(" % " ) ;
delay(2000);
if (h >= 75 ){
 digitalWrite(ledPin,HIGH);
  digitalWrite(ledPin2,HIGH);
 delay(2000);
 digitalWrite(ledPin,LOW);  
  digitalWrite(ledPin2,LOW);
}
}
