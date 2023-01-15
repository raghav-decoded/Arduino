  FV 
  
  
  
  
  
  
  
  #include <Servo.h> //Loading the servo library

int pos = 0 ; //Declare and initialize pos variable
int servoPin1 = 9 ; // Servo is on pin 9

int potReading ; // Declare variable for potentiometer reading
int PotPin=A0;
 
 Servo myPointer1 ; // Create a Servo object called myPointer 

void setup() {
  Serial.begin(9600);
  myPointer1.attach(servoPin1);
}

void loop() {
potReading = analogRead(PotPin);      // Read potentiometre
potReading = map ( potReading , 0,1023,0,180);
//pos = (155.0/1023.0)*potReading + 15 ; // calculate pos
pos = potReading ; 
myPointer1.write(pos);                 // write pos to servo
}
