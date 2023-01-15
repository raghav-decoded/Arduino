#include <Servo.h> //Loading the servo library
int pos = 0 ; //Declare and initialize pos variable
int servoPin = 9 ; // Servo is on pin 9
int potReading ; // Declare variable for potentiometer reading
int PotPin=A0;
int servoPin2 = 8 , potPin = A1,pos2=0,potReading2;
 
 Servo myPointer ; // Create a Servo object called myPointer 
 Servo ptr;

//#include <Servo.h>

void setup() {
  Serial.begin(9600);
  myPointer.attach(servoPin);
  ptr.attach(servoPin2);
}

void loop() {


potReading = analogRead(PotPin);      // Read potentiometre
potReading = map ( potReading , 0,1023,0,180);
//pos = (155.0/1023.0)*potReading + 15 ; // calculate pos
pos = potReading ;
myPointer.write(pos);                 // write pos to servo

potReading2 = analogRead(potPin);      // Read potentiometre
potReading2 = map ( potReading2 , 0,1023,0,180);
//pos = (155.0/1023.0)*potReading + 15 ; // calculate pos
pos2 = potReading2 ;
ptr.write(pos2);                 // write pos to servo

}
