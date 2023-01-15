int redPin = 1 ;
int greenPin = 2 ;
int bluePin = 3 ;

int S2 = 7 ;
int S3 = 8 ;
int outPin = 4 ;

int rColorStrength;
int gColorStrength;
int bColorStrength;                       //int to float

 unsigned int  pulseWidth ;                //float pulseWidth 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(redPin,OUTPUT);
pinMode(greenPin,OUTPUT);
pinMode(bluePin,OUTPUT);

pinMode(S2,OUTPUT);
pinMode(S3,OUTPUT);
pinMode(outPin,INPUT);

}

void loop() {
//Common Anode RGB LED

  //Lets start by reading the red component .
  //S2 and S3 should be set LOW.
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
   pulseWidth = pulseIn(outPin,LOW);
   rColorStrength = pulseWidth/400-1          ;                             //pulseWidth 102400 max.

  
   //Lets start by reading the green component .
  //S2 and S3 should be set HIGH.
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
   pulseWidth = pulseIn(outPin,LOW);
   gColorStrength =  pulseWidth/400-1          ;                            
 

   //Lets start by reading the blue component .
  //S2 and S3 should be set LOW and HIGH respectively.
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH); 
   pulseWidth = pulseIn(outPin,LOW);
   bColorStrength =   pulseWidth/400-1          ;                          // pulseWidth 102400 max .
 

  Serial.print(rColorStrength);
  Serial.print(",");
  Serial.print(gColorStrength);
  Serial.print(",");
  Serial.println(bColorStrength);

 if (rColorStrength <= 5 ) {
  rColorStrength = rColorStrength ;
  gColorStrength = 255 ;
  bColorStrength = 255 ;
 }

 else
 {
 if(rColorStrength < gColorStrength && gColorStrength < bColorStrength ) {   //RGB
  rColorStrength = rColorStrength ; 
  gColorStrength = bColorStrength ;
  bColorStrength = 255 ;
 }

  if(rColorStrength < bColorStrength && bColorStrength < gColorStrength ) {   //RBG
  rColorStrength = rColorStrength ; 
  bColorStrength = bColorStrength  ;
  gColorStrength = 255 ;
 }

 if(gColorStrength < rColorStrength && rColorStrength < bColorStrength ) {    //GRB
  gColorStrength= gColorStrength;
  rColorStrength = rColorStrength ;
  bColorStrength = 255 ;
 }

 if(gColorStrength < bColorStrength && bColorStrength < rColorStrength ) {    //GBR
  gColorStrength =  gColorStrength; 
  bColorStrength =  bColorStrength;
  rColorStrength = 255 ;
 }

if(bColorStrength < rColorStrength && rColorStrength < gColorStrength ) {     //BRG
  bColorStrength = bColorStrength ; 
  rColorStrength = rColorStrength ;
  gColorStrength = 255 ;
 }

 if(bColorStrength < gColorStrength && gColorStrength < rColorStrength ) {     //BGR
  bColorStrength = bColorStrength ; 
  gColorStrength = gColorStrength ;
  rColorStrength = 255 ;
 }
 }
   
 analogWrite(redPin,rColorStrength);
 analogWrite(greenPin,gColorStrength);
 analogWrite(bluePin,bColorStrength);
}
