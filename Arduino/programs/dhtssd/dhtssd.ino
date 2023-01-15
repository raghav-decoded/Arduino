#include<dht.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define dataPin 8
dht DHT ;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int trigPin=13 ; //Connect Sensor trig to pin 13
int echoPin=11 ;

float pingTime ;
float targetDistance ;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
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
  display.setCursor(0,0);
  display.println(F("Hello , "));
  display.display();
    display.clearDisplay();
  delay(2000);
  }

void loop () {
  display.setTextSize(1);
  display.setCursor(0,0);
 
 int readData = DHT.read11(dataPin);
float t = DHT.temperature ; 
float h = DHT.humidity ; 
 
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);
  pingTime = pulseIn(echoPin,HIGH);
  pingTime=pingTime/1000000; //Conversion from micro seconds to seconds
  float speedofSound = 332.0*(1.0+(t/546.0));
  targetDistance=(( pingTime * speedofSound ) /2 )* 100;
  
  display.print(F("Temperature = "));
  display.print(t);
  display.println(F(" C"));
  display.print(F("Humidity = "));
  display.print(h);
   display.println(F("%"));
   display.println(F(" "));
  display.println(F("Velocity of Sound  = "));
  display.print(speedofSound);
   display.println(F(" m/s"));
   display.println(F(" "));
  display.println(F("Target Distance = "));
  display.print(targetDistance);
   display.println(F("cm"));
  display.display();
  delay(2000);
  display.clearDisplay();
 
}

  
