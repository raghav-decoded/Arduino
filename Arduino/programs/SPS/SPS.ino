#include <Servo.h> //Loading the servo library


int servoPin1 = 9 ; // Servo is on pin 9
int servoPin2 = 10 ;
int servoPin3 = 11 ;
int servoPin4 = 12 ;
int servoPin5 = 13 ;

 Servo myPointer1  ; // Create a Servo object called myPointer 
 Servo myPointer2 ;
  Servo myPointer3 ;
   Servo myPointer4 ;
    Servo myPointer5 ;

void setup() {
  Serial.begin(9600);
  myPointer1.attach(servoPin1);
   myPointer2.attach(servoPin2);
    myPointer3.attach(servoPin3);
     myPointer4.attach(servoPin4);
      myPointer5.attach(servoPin5);
     
}

void loop() {
int  r = random(0,3);
Serial.print(r);
  if (r == 0) {
  stone();
  delay(5000);
  }
  else if ( r == 1){
  paper();
  delay(5000);
  }
  else if (r == 2) {
  scisor();
delay(5000);
}
}

void stone(void) {
  myPointer1.write(180);
   myPointer2.write(180);
    myPointer3.write(180);
     myPointer4.write(180);
      myPointer5.write(180);
}

void paper(void) {
  myPointer1.write(0);
   myPointer2.write(0);
    myPointer3.write(0);
     myPointer4.write(0);
      myPointer5.write(0);
}

void scisor(void) {
  myPointer1.write(0);
   myPointer2.write(180);
    myPointer3.write(180);
     myPointer4.write(0);
      myPointer5.write(0);
}
