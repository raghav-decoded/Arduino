#include<LiquidCrystal.h> //Load the Liquid crystal library
LiquidCrystal LCD(10,9,5,4,3,2) ; // Creating the LiquidCrystal object named LCD
int myCounter=0; // declare your variable myCounter

void setup() {
  
LCD.begin(16,2); // Tell Arduino our LCD has 16 columns and 2 rows
LCD.setCursor(0,0) ;//Set LCD cursor to upper left corner of display
LCD.print("My Timer : ") ; //Print our first line
}

void loop() {

for (myCounter = 1 ; myCounter <= 10 ; myCounter=myCounter + 1) {

LCD.setCursor(0,1); // Second Cursor to first column and second row
LCD.print(myCounter); //print your counter
LCD.print(" seconds "); // prints units
delay(1000);
  
  } 

for (myCounter = 10 ; myCounter >= 0 ; myCounter=myCounter - 1) {

LCD.setCursor(0,1); // Second Cursor to first column and second row
LCD.print(myCounter); //print your counter
LCD.print(" seconds "); // prints units
delay(1000);
  
  }  
}
