#include<Servo.h>

Servo switcher;
int servopin = 9 ;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
switcher.attach(servopin);
timer();
}
void loop(){}
void timer() {
  // put your main code here, to run repeatedly
   int m,h,s,sec;
   switcher.write(0);
 /*  Serial.println( "Enter the number of hours = ") ;
   while (Serial.available() == 0) {}
   h = Serial.parseInt() ;
   delay(1000);
   Serial.println("Enter the number of minutes = ");
   while (Serial.available() == 0) {}
   m = Serial.parseInt() ;
   delay(1000);
   Serial.println("Enter the number of seconds = ");
   while (Serial.available() == 0) {}
   s = Serial.parseInt() ;
   delay(1000);*/
   s = 10;
   m = 0;
   h = 0 ;
     sec = s+ m*60 + h*3600;

   while(sec){
   sec--;
   if (s>0){
     s--; }
   if(s==0 && m>0 ){
     m-- ;
     s=60;}
   if(m==0 && h>0){
     h-- ;
     m=60;
     }
   if (sec==0)
     s=0;
   Serial.print("Time left: ");
   Serial.print(h);
   Serial.print(" H ");
   Serial.print(m);
   Serial.print(" M ");
   Serial.print(s);
   Serial.println("S");
   delay(1000);
   }
   delay(1000);
   Serial.print("Time up!");
   switcher.write(180);
}
