#include <SPI.h>
#include <SD.h>

File myFile ; // Creating File object

int pinCS = 10 ;

void setup() {
  // put your setup code here, to run once:
     Serial.begin(9600);
     pinMode(pinCS , OUTPUT) ; 

     //SD card initialization
     if ( SD.begin()) {
      Serial.println("SD card ready to use . ") ;
     }
     else {
      Serial.println("SD card initialization unsuccessful.") ;
      return ; 
     }

     //Create/Open file 
     myFile = SD.open("text.txt",FILE_WRITE) ;

     // if the file opened okay , write to it :
     if (myFile) {
      Serial.println("Writing to file ...") ; 
      //Write to file 
      myFile.println("Testing 1 , 2 , 3 ...") ;
      myFile.close() ;  //Close the file 
      Serial.println("Done");
     }
     // if the file did not open prompt that there is an error . 
     else {
      Serial.println("error opening text.txt ") ; 
     }

     // Reading the file 
     myFile = SD.open("text.txt") ; 
     if (myFile) {
      Serial.println("Read") ;
      //Reading the entire file 
      while (myFile.available()) {
        Serial.write(myFile.read()) ;  
      }
      myFile.close() ;
     }
     else {
      Serial.println("error opening text.txt ") ; 
     }
}

void loop() {
  // put your main code here, to run repeatedly:
  //empty 
}
