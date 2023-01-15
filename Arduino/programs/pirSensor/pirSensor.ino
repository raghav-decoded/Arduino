int pirSensor = 2 ;
int LEDPIN = 13 ;
int sensorValue = 0; 

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
pinMode(pirSensor,INPUT);
pinMode(LEDPIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
sensorValue = digitalRead(pirSensor);
digitalWrite(LEDPIN,sensorValue);
Serial.println(sensorValue);
if(sensorValue == 1 ) 
  digitalWrite(LEDPIN,LOW);
}
