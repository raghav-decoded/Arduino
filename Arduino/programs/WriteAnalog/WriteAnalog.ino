int pin = 6;
//float writevalue = 3.8 ;

void setup() {
  // put your setup code here, to run once:
pinMode ( pin ,OUTPUT) ;
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
//writevalue = writevalue *51 ; 
//Serial.println(writevalue);
analogWrite(pin ,194 );
}
