int E = 13 ;
int D = 12 ;
int C = 11 ;
int DP = 10 ;
int B = 9 ;
int A = 8 ;
int F = 7 ;
int G = 6 ;

void one (){
digitalWrite(E, LOW); 
digitalWrite(D,LOW);
digitalWrite(C,HIGH);
digitalWrite(DP,LOW);
digitalWrite(B,HIGH);  
digitalWrite(A,LOW);
digitalWrite(F,LOW);
digitalWrite(G,LOW);
}

void two (){
digitalWrite(E, HIGH); //Counter intuively high turns it off
digitalWrite(D,HIGH);
digitalWrite(C,LOW);
digitalWrite(DP,LOW);
digitalWrite(B,HIGH);  // Turns on
digitalWrite(A,HIGH);
digitalWrite(F,LOW);
digitalWrite(G,HIGH);
}

void three (){
digitalWrite(E, LOW); //Counter intuively high turns it off
digitalWrite(D,HIGH);
digitalWrite(C,HIGH);
digitalWrite(DP,LOW);
digitalWrite(B,HIGH);  // Turns on
digitalWrite(A,HIGH);
digitalWrite(F,LOW);
digitalWrite(G,HIGH);
}

void four (){
digitalWrite(E, LOW); //Counter intuively high turns it off
digitalWrite(D,LOW);
digitalWrite(C,HIGH);
digitalWrite(DP,LOW);
digitalWrite(B,HIGH);  // Turns on
digitalWrite(A,LOW);
digitalWrite(F,HIGH);
digitalWrite(G,HIGH);
}

void five (){
digitalWrite(E, LOW); //Counter intuively high turns it off
digitalWrite(D,HIGH);
digitalWrite(C,HIGH);
digitalWrite(DP,LOW);
digitalWrite(B,LOW);  // Turns on
digitalWrite(A,HIGH);
digitalWrite(F,HIGH);
digitalWrite(G,HIGH);
}

void six (){
digitalWrite(E, HIGH); //Counter intuively high turns it off
digitalWrite(D,HIGH);
digitalWrite(C,HIGH);
digitalWrite(DP,LOW);
digitalWrite(B,LOW);  // Turns on
digitalWrite(A,HIGH);
digitalWrite(F,HIGH);
digitalWrite(G,HIGH);
}

void seven (){
digitalWrite(E, LOW); //Counter intuively high turns it off
digitalWrite(D, LOW );
digitalWrite(C,HIGH);
digitalWrite(DP,LOW);
digitalWrite(B,HIGH);  // Turns on
digitalWrite(A,HIGH);
digitalWrite(F,LOW);
digitalWrite(G,LOW);
}

void eight (){
digitalWrite(E, HIGH); //Counter intuively high turns it off
digitalWrite(D,HIGH);
digitalWrite(C,HIGH);
digitalWrite(DP,LOW);
digitalWrite(B,HIGH);  // Turns on
digitalWrite(A,HIGH);
digitalWrite(F,HIGH);
digitalWrite(G,HIGH);
}

void nine  (){
digitalWrite(E, LOW); //Counter intuively high turns it off
digitalWrite(D,HIGH);
digitalWrite(C,HIGH);
digitalWrite(DP,LOW);
digitalWrite(B,HIGH);  // Turns on
digitalWrite(A,HIGH);
digitalWrite(F,HIGH);
digitalWrite(G,HIGH);
}

void zero  (){
digitalWrite(E, HIGH); //Counter intuively high turns it off
digitalWrite(D,HIGH);
digitalWrite(C,HIGH);
digitalWrite(DP,LOW);
digitalWrite(B,HIGH);  // Turns on
digitalWrite(A,HIGH);
digitalWrite(F,HIGH);
digitalWrite(G,LOW);
}

void setup() {
 pinMode(E,OUTPUT);
 pinMode(D,OUTPUT);
 pinMode(C,OUTPUT);
 pinMode(DP,OUTPUT);
 pinMode(B,OUTPUT);
 pinMode(A,OUTPUT);
 pinMode(F,OUTPUT);
 pinMode(G,OUTPUT);
}

void loop() {
 one();
 delay(1000);
 two(); 
 delay(1000);
 three();
delay(1000);
 four();
delay(1000);
 five();
delay(1000);
 six();
delay(1000);
 seven();
delay(1000);
 eight();
delay(1000);
 nine();
delay(1000);
 zero();
 delay(1000);
}
