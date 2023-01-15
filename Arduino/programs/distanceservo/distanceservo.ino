#include <Servo.h>

int trigPin=13 ;
int echoPin=11;
int servoControlPin=6;

float pingTime ;        //Time for ping travel and return
float targetDistance ;  //to calculate
float speedofSound= 34300.0 ; //Speed of sound in cm/s 
float servoAngle ;      //angle of servo

Servo myPointer ; 

void setup() {

 Serial.begin(9600);
 pinMode(servoControlPin , OUTPUT);
 pinMode(trigPin , OUTPUT) ;
 pinMode(echoPin , INPUT) ;

 myPointer.attach(servoControlPin);

}

void loop() {

digitalWrite(trigPin ,LOW ) ;
delayMicroseconds(2000);
digitalWrite(trigPin , HIGH ) ;
delayMicroseconds(15);
digitalWrite(trigPin , LOW ) ;

pingTime = pulseIn(echoPin,HIGH) ;
pingTime = (pingTime/1000000.0) ;

targetDistance= (speedofSound * pingTime) ;
targetDistance = (targetDistance / 2 ); //Accounts for round trip of ping to target

Serial.print("The distance is ") ;
Serial.print(targetDistance);
Serial.println(" centimetres");
//delay(100);

servoAngle= (28/3) * targetDistance  + 20 ;
myPointer.write(servoAngle);
}
