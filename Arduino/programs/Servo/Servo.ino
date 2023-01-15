#include <Servo.h> //Loading the servo library
int pos = 0 ; //Declare and initialize pos variable
int servoPin = 2 ; // Servo is on pin 9
int servoDelay = 25 ;
 
 Servo myPointer ; // Create a Servo object called myPointer 

//#include <Servo.h>

void setup() {
  Serial.begin(9600);
  myPointer.attach(servoPin);
}

void loop() {


Serial.println("Where would you like to position the servo");
while (Serial.available() == 0) {
  }

pos = Serial.parseInt();  //read user input

myPointer.write(pos);     //write pos to servo
}
