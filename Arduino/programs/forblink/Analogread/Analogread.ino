int potPen=A0;
int readValue;
float Voltage ;

void setup() {
  pinMode(potPen,INPUT);
  Serial.begin(9600);

}

void loop() {
  readValue = analogRead(potPen);
  Voltage = (5.0/1023.0)*(readValue); 
  Serial.println(Voltage);
  delay(250);

}
