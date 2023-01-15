#include <Servo.h> //Loading the servo library
int pos = 0 ; //Declare and initialize pos variable
int servoPin = 9 ; // Servo is on pin 9 
int servoDelay = 25 ;
 
 Servo myPointer ; // Create a Servo object called myPointer 

//#include <Servo.h>

void setup() {
  Serial.begin(9600);
  myPointer.attach(servoPin);
}

void loop() {

 for (pos=15 ; pos <=170 ; pos=pos+2) { 
  myPointer.write(pos) ; // send servo to pos
  delay(servoDelay) ; // pause a moment 
  }

for (pos=170 ; pos >=15 ; pos--) { 
  myPointer.write(pos) ; // send servo to pos
  delay(servoDelay) ; // pause a moment 
  }
}
