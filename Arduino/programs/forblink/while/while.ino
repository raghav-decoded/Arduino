void setup() {
  Serial.begin(9600);

}

void loop() {

   int j = 1 ; 
   while ( j<=10  ) { 
   Serial.println(j); 
   j=j+1;
    }
}
