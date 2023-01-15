#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

#include<dht.h>
#include <Wire.h>
#include <SPI.h>          // f.k. for Arduino-1.5.2
#include "Adafruit_GFX.h"// Hardware-specific library
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;
//#include <Adafruit_TFTLCD.h>
//Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

#define dataPin 22
dht DHT ;

// Assign human-readable names to some common 16-bit color values:
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

void setup(void) {

 Serial.begin(9600);
    uint32_t when = millis();
    //    while (!Serial) ;   //hangs a Leonardo until you connect a Serial
    if (!Serial) delay(5000);           //allow some time for Leonardo
    Serial.println("Serial took " + String((millis() - when)) + "ms to start");
    //    tft.reset();                 //hardware reset
    uint16_t ID = tft.readID(); //
    Serial.print("ID = 0x");
    Serial.println(ID, HEX);
    if (ID == 0xD3D3) ID = 0x9481; // write-only shield
//    ID = 0x9329;                             // force ID
    tft.begin(ID);

   tft.setRotation(1); // Need for the Mega, please changed for your choice or rotation initial

  // *** SPFD5408 change -- End

  progmemPrintln(PSTR("Benchmark                Time (microseconds)"));
 progmemPrint(PSTR("Screen fill              "));
  Serial.println(testFillScreen());
  delay(500);
  //Start up
  tft.fillScreen(BLACK);
  tft.setCursor(0,90);//240 x 320
  tft.setTextColor(RED);  tft.setTextSize(3);
  tft.println("QUARDBAUD ");
  tft.setTextColor(BLUE);
  tft.println(" TECHNOLOGIES");
  tft.setTextSize(2);
  tft.setTextColor(GREEN);
  tft.println("The way to infinity.");
  tft.println("");
 delay(4000);
 tft.fillScreen(BLACK);
  }

void loop(void) {

   tft.setCursor(0,0);
   tft.setRotation(1);
  int readData = DHT.read11(dataPin);
float t = DHT.temperature ; 
float h = DHT.humidity ; 
tft.setTextSize(4);

tft.setTextColor(YELLOW);
tft.println("WEATHER");
tft.println("");

tft.setTextSize(2);
if(t > 25.0){
tft.setTextColor(RED);
tft.println("Temperature : ");
tft.println("");
tft.print(t);
tft.println(" deg. Celsius");          // In Celsius 
tft.print(((9.0/5.0)*t)+32.0);
tft.println(" deg. Fahrenheit");       //In Fahrenheit
tft.print(t+273.15);
tft.println(" Kelvin");          // In Kelvin
tft.println("");
}
if(t <= 25.0 && t >= 20){
tft.setTextColor(GREEN);
tft.println("Temperature : ");
tft.println("");
tft.print(t);
tft.println(" deg. Celsius");          // In Celsius 
tft.print(((9.0/5.0)*t)+32.0);
tft.println(" deg. Fahrenheit");       //In Fahrenheit
tft.print(t+273.15);
tft.println(" Kelvin");          // In Kelvin
tft.println("");
}
if(t < 20.0){
tft.setTextColor(CYAN);
tft.println("Temperature : ");
tft.println("");
tft.print(t);
tft.println(" deg. Celsius");          // In Celsius 
tft.print(((9.0/5.0)*t)+32.0);
tft.println(" deg. Fahrenheit");       //In Fahrenheit
tft.print(t+273.15);
tft.println(" Kelvin");          // In Kelvin
tft.println("");
}

tft.setTextSize(2);
tft.setTextColor(BLUE);
tft.print("Humidity : ");
tft.print(h);
tft.println(" %");

delay(2000); 
 tft.fillScreen(BLACK);
}

unsigned long testFillScreen() {
  unsigned long start = micros();
  tft.fillScreen(MAGENTA);
  tft.fillScreen(RED);
  tft.fillScreen(GREEN);
  tft.fillScreen(BLUE);
  tft.fillScreen(WHITE);
  return micros() - start;
}

// Copy string from flash to serial port
// Source string MUST be inside a PSTR() declaration!
void progmemPrint(const char *str) {
  char c;
  while(c = pgm_read_byte(str++)) Serial.print(c);
}

// Same as above, with trailing newline
void progmemPrintln(const char *str) {
  progmemPrint(str);
  Serial.println();
}
