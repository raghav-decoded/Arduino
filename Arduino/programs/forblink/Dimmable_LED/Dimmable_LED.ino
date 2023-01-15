int LEDPin = 9;
int potPin = A0 ;
int readValue;
float writeValue;


void setup() {

Serial.begin(9600);
pinMode (LEDPin,OUTPUT);
pinMode (potPin,INPUT);

}

void loop() {
 
readValue=analogRead(potPin);
writeValue=(5.0/1023.0)*readValue ;
analogWrite(LEDPin,writeValue);
delay(250);
Serial.print("You are writing the value of ");
Serial.println(writeValue);
}
