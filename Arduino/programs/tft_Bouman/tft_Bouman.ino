// IMPORTANT: Adafruit_TFTLCD LIBRARY MUST BE SPECIFICALLY
// CONFIGURED FOR EITHER THE TFT SHIELD OR THE BREAKOUT BOARD.
// SEE RELEVANT COMMENTS IN Adafruit_TFTLCD.h FOR SETUP.

// Modified for SPFD5408 Library by Joao Lopes
// Version 0.9.2 - Rotation for Mega and screen initial

// *** SPFD5408 change -- Begin
#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
#include <SPFD5408_TouchScreen.h>
// *** SPFD5408 change -- End

// The control pins for the LCD can be assigned to any digital or
// analog pins...but we'll use the analog pins as this allows us to
// double up the pins with the touch screen (see the TFT paint example).
#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0

#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

// When using the BREAKOUT BOARD only, use these 8 data lines to the LCD:
// For the Arduino Uno, Duemilanove, Diecimila, etc.:
//   D0 connects to digital pin 8  (Notice these are
//   D1 connects to digital pin 9   NOT in order!)
//   D2 connects to digital pin 2
//   D3 connects to digital pin 3
//   D4 connects to digital pin 4
//   D5 connects to digital pin 5
//   D6 connects to digital pin 6
//   D7 connects to digital pin 7
// For the Arduino Mega, use digital pins 22 through 29
// (on the 2-row header at the end of the board).

// Assign human-readable names to some common 16-bit color values:
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
// If using the shield, all control and data lines are fixed, and
// a simpler declaration can optionally be used:
// Adafruit_TFTLCD tft;

// -- Setup

void setup(void) {

  Serial.begin(9600);

  progmemPrintln(PSTR("TFT LCD test"));

#ifdef USE_ADAFRUIT_SHIELD_PINOUT
  progmemPrintln(PSTR("Using Adafruit 2.8\" TFT Arduino Shield Pinout"));
#else
  progmemPrintln(PSTR("Using Adafruit 2.8\" TFT Breakout Board Pinout"));
#endif

  tft.reset();

  tft.begin(0x9341); // SDFP5408

   tft.setRotation(0); // Need for the Mega, please changed for your choice or rotation initial

  // *** SPFD5408 change -- End

  progmemPrintln(PSTR("Benchmark                Time (microseconds)"));
 progmemPrint(PSTR("Screen fill              "));
  Serial.println(testFillScreen());
  delay(500);
  
  }

void loop(void) {

   tft.fillScreen(BLACK);
  tft.setCursor(0,0);//240 x 320
  tft.setTextColor(RED);  tft.setTextSize(3);
  tft.println("  QUARDBAUD ");
  tft.setTextColor(BLUE);
  tft.println(" TECHNOLOGIES");
  tft.setTextSize(2);
  tft.setTextColor(GREEN);
  tft.println("The way to infinity.");
  tft.println("");
  tft.setRotation(3);
  tft.fillScreen(BLACK);
  tft.setTextColor(YELLOW);
  tft.println("Thank you Katie Bouman for letting me see the wonder of this universe ");
  tft.print("      ,the black hole.");
 delay(4000);
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
