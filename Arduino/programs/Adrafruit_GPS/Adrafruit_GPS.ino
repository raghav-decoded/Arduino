#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial (3,2);
Adafruit_GPS GPS (&mySerial);

String NMEA1;
String NMEA2;
char c ;
 
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
GPS.begin(9600);
GPS.sendCommand("$PGCMD,33,0*6D");
GPS.sendCommand(PMTK_SET_NMEA_UPDATE_10HZ);
GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
delay(1000);

}

void loop() {
  // put your main code here, to run repeatedly:

readGPS();
delay(7500);//Simulation of other sensors
}

void readGPS()
{
  clearGPS();
  while(!GPS.newNMEAreceived()) {
    c = GPS.read();
    }
    GPS.parse(GPS.lastNMEA());
    NMEA1=GPS.lastNMEA();

     while(!GPS.newNMEAreceived()) {
    c = GPS.read();
    }
    GPS.parse(GPS.lastNMEA());
    NMEA2=GPS.lastNMEA();

  Serial.println(NMEA1);
  Serial.println(NMEA2);
  Serial.println("");
  }

  void clearGPS () {
    while(!GPS.newNMEAreceived()) {
    c = GPS.read();
    }
    GPS.parse(GPS.lastNMEA());

    while(!GPS.newNMEAreceived()) {
    c = GPS.read();
    } GPS.parse(GPS.lastNMEA());
  
  while(!GPS.newNMEAreceived()) {
    c = GPS.read();
    } GPS.parse(GPS.lastNMEA());
  }
