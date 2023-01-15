String myName ; 
int age ;
float height ;

void setup() {
  Serial.begin(9600);

}

void loop() {

 Serial.println("Please enter your name :  "); //Prompt the user for his name 
   while(Serial.available()==0);{             //Waiting for user input
   }
 myName = Serial.readString() ;                //Read the string 

 Serial.println("How old are you ? : ");       //Prompt the user for his age
  while(Serial.available()==0);{               //Waiting for user input
   }
 age = Serial.parseInt();                      //Read the integer

 Serial.println("How tall are you ? : ");
  while(Serial.available()==0);{
    }
 height = Serial.parseFloat();

 Serial.print("Hello ");
 Serial.print(myName);
 Serial.print(" , you are ");
 Serial.print(age);
 Serial.print(" years old ");
 Serial.print( " and you are ");
 Serial.print(height);
 Serial.println(" feet tall .");
}
