#include<LiquidCrystal.h>
LiquidCrystal LCD(10,9,5,4,3,2) ;

int trigPin=13 ; //Connect Sensor trig to pin 13
int echoPin=11 ;

float pingTime ;
float targetDistance ;
float speedofSound=34300.0 ; //speed of sound in cm/s
 
void setup() {
 Serial.begin(9600);
 pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 
 LCD.begin(16,2);
 LCD.setCursor(0,0);
 LCD.print("TARGET DISTANCE"); 
}

void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  
  pingTime = pulseIn(echoPin,HIGH);
  
  pingTime=pingTime/1000000; //Conversion from micro seconds to seconds
  targetDistance=( pingTime * speedofSound ) /2 ;
  LCD.setCursor(0,1);
   LCD.print("                ");
 LCD.setCursor(0,1);
  LCD.print(targetDistance) ;
  LCD.print(" cm " ) ;
  delay(250);
}
