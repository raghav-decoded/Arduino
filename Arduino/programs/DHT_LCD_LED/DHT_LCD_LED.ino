#include <dht.h>
#include <LiquidCrystal.h>
LiquidCrystal LCD(10,9,5,4,3,2) ;

#define dataPin 8
dht DHT ;

int LedPin =13;

void setup() {
  Serial.begin(9600);
  LCD.begin(16,2);
  LCD.setCursor(0,0);
pinMode(LedPin,HIGH);
}

void loop() {
int readData = DHT.read11(dataPin);
float t = DHT.temperature ; 
float h = DHT.humidity ;

 if (h > 72.0){
  digitalWrite(LedPin,HIGH);
  delay(1000);
  digitalWrite(LedPin,LOW);
 }


LCD.setCursor(0,0);
LCD.print("Temp. = " );
LCD.print(t);
LCD.print(" C " );

LCD.setCursor(0,1);
LCD.print("Humidity = ") ;
LCD.print(h);
LCD.print(" % " ) ;
delay(1500);

}
