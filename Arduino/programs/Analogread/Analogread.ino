int rpin = A0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(rpin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
float voltage = analogRead(rpin)* (9.0/1023.0);
Serial.print(voltage);
Serial.println(" V ");
}
