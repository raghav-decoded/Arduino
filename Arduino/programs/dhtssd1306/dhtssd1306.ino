
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
  display.setCursor(0,0);
  display.println(F("Hello , "));
  display.display();
    display.clearDisplay();
  delay(2000);
  }

void loop () {
  display.setTextSize(1);
  display.setCursor(0,0);
/*  display.println(F("Random no. generator "));
  display.setCursor(50,32);
  display.setTextSize(3);
  display.println(random(1,7));
  display.display();
  delay(1000);*/
  
   float readData = DHT.read11(dataPin);
float t = DHT.temperature ;  
float h = DHT.humidity ;
display.print(F("Temp. = ") );
display.print(t);
Serial.print(t);
display.print(F(" Celsius ") );
display.println(F("Humidity = "));
display.print(h);
display.print(F(" % " ));
display.display();
display.clearDisplay();
}

  
