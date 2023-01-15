int redPin = 7;
int greenPin = 5 ;
int bluePin = 6 ; 
int CommonAnode =8 ;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(bluePin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(CommonAnode,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(CommonAnode,HIGH);
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,LOW);
    digitalWrite(redPin,HIGH);

}
