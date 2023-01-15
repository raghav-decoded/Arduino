#include <Keyboard.h>

const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output
int x, y;
void setup() 
{
  pinMode(SW_pin, INPUT); // SW pin set as input
  digitalWrite(SW_pin, HIGH); // A high value is written to SW pin
  Serial.begin(115200);
  Keyboard.begin();
}
void loop() 
{
  x = analogRead(X_pin); // output of X_pin is read
  if (x == 1023) // check whether the value of x = 1023
  {
    Serial.println("Up:");
    Keyboard.press(218); // key moves up
  }
  else
  {
    Keyboard.release(218);  // release the key
  }
  x = analogRead(X_pin);  // output of X_pin is read
  if (x == 0) // check whether the value of x = 0

  {
    Serial.println("Down:");
    Keyboard.press(217); // key moves down
  }
  else
  {
    Keyboard.release(217);  // release the key
  }
  y = analogRead(Y_pin);  // output of Y_pin is read

    if (y == 1023) // check whether the value of  y = 1023
    {
      Serial.println("Right:"); 
      Keyboard.press(216); // key moves right
    }
    else
    {
     Keyboard.release(216);  // release the key
    }
  y = analogRead(Y_pin); // output of Y_pin is read

    if (y == 0) // check whether the value of y = 0
    {
      Serial.println("Left:");
      Keyboard.press(215); // key moves left

  }
  else
  {
    Keyboard.release(215);  // release the key
  }
  int z = digitalRead(SW_pin); // read the value of SW pin
    if (z == 0) //check whether the value of z = 0
    {
      Serial.println("Enter:");
      Keyboard.println(); //enter key is pressed
   }
  delay(500);
}
