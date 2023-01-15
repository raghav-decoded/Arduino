
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int buttonPin1 = 2 ;
int buttonState1 =0 ;
int buttonPin2 = 3 ;
int buttonState2 =0 ;
int potPin = A0 ;

void setup() {
  Serial.begin(9600);
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,20);  //(128,32)
  display.println(F("QUARDBAUD"));
    display.println(F("TECHNOLOGIES"));
  display.display();
    display.clearDisplay();
  delay(2000);
  pinMode(buttonPin1,INPUT);
   pinMode(buttonPin2,INPUT);
  }
String w ;

void loop () {
  int potReading ;
  char ch;
  
  display.setCursor(0,20);
  display.print(w);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println(F("Keyboard"));
  
  potReading = analogRead(potPin);      // Read potentiometre
  Serial.println(potReading);
  potReading = map ( potReading , 0,1023,32,122);
  ch = potReading;
  display.println(ch);
 
  display.display();
  delay(300);
  display.clearDisplay();
  display.setCursor(127,0);
 buttonState1 = digitalRead(buttonPin1);
 if(buttonState1 == HIGH){ 
  w+=ch;
  indicator();
  //display.print(F("."));
  } 
  display.setCursor(0,20);
  display.print(w);
  
  display.setCursor(127,0);
   buttonState2 = digitalRead(buttonPin2);
  if(buttonState2==HIGH){
    //display.print(F("."));
    w+=' ';
     indicator();
    }
    
     buttonState2 = digitalRead(buttonPin2);
      buttonState1 = digitalRead(buttonPin1);
   display.setCursor(127,0);
if(buttonState1&&buttonState2==HIGH){
 // display.print(F(".."));
  w="";
  indicator();
  }
}

void indicator(){
  display.drawPixel(127,0,WHITE);
  display.drawPixel(127,1,WHITE);
  display.drawPixel(127,2,WHITE);
  display.drawPixel(127,3,WHITE);
  display.drawPixel(128,0,WHITE);
  display.drawPixel(128,1,WHITE);
  display.drawPixel(128,2,WHITE);
  display.drawPixel(128,3,WHITE);
  }
  
