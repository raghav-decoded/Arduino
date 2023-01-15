int LedRed=9;
int LedGreen=10;
int rontime=500;
int roftime=500;
int gontime=500;
int goftime=500;
int numRedBlink=5;
int numGreenBlink;
String redmessage="The red LED is Blinking!";
String greenMessage="The green LED is Blinking";
int writevalue;

void setup() {
   Serial.begin(115200);
  String va1 = " Welcome to ";
  String va2 = " My Program ";
  String va3;
  va3=va1+va2;                       //Concatenation of string (concatenating va1 and va2 to va3.).
  Serial.println(va3);
  pinMode(LedGreen,OUTPUT);
  pinMode(LedRed,OUTPUT);

Serial.println("What number do you want to write ?");  //Prompt 
while(Serial.available()==0) {}
writevalue = Serial.parseInt(); // serial.readString

Serial.println("How many times do you want to blink GREEN LED ?");  //Prompt for user input
while(Serial.available()==0) {}
numGreenBlink = Serial.parseInt(); // serial.readString

}

void loop() {
int j = 1 ;
Serial.println("  ");
Serial.println(redmessage);
// for (int j = 1 ; j <= numRedBlink ; j++ )
 while ( j<= numRedBlink  ){
   Serial.print("  You are on blink number = ");
   Serial.println(j);
    analogWrite(LedRed,writevalue); // Apply analog voltage to Red LED            digitalWrite(LedRed,HIGH);
     delay(rontime);
    analogWrite(LedRed,writevalue) ; //Apply analog voltage to Red LED             digitalWrite(LedRed,LOW);
     delay(roftime);
j++;
}

Serial.println("  ");
Serial.println(greenMessage);
for (int j = 1 ; j <= numGreenBlink ; j++ ) {
 Serial.print("   You are on blink number =");
 Serial.println(j);
 digitalWrite(LedGreen,HIGH);
  delay(gontime);
 digitalWrite(LedGreen,LOW);
  delay(goftime); 
}
}
