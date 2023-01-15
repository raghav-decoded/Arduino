int trigPin = 13 ; //Sensor trig pin is connected to 13
int echoPin = 11 ; // Sensor echoPin is connected to 11
float pingTime ; // Time for pin to hit the target and return
float speedSound ; // To calculate the speed of sound
float targetDistance =  15 ; //Target distance 15 cm

void setup() {
Serial.begin(9600);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);

}

void loop() {

digitalWrite(trigPin,LOW);
delayMicroseconds(2000);  //pause to let signal settle
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);    //pause with trigger pin high
digitalWrite(trigPin,LOW); //finish trigger pulse by bringing it low 

pingTime = pulseIn(echoPin,HIGH) ; //Mesure pin travel time in microseconds
speedSound = (2 * targetDistance)/pingTime ; //Gives value in cm/microseconds  
speedSound = speedSound *10000 ;    //Gives speed of sound in meters per seconds
Serial.print("The speed of sound is ");
Serial.print(speedSound);
Serial.println(" m/s " ) ;
delay(3000);
}
