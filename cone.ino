/*
Andrea Toscano
Universita' degli Studi di Milano

Sample script - Reading some info from U-Blox Neo M8N GPS/GLONASS
*/

#include "Ublox.h"
#include "elapsedMillis.h"

#define SERIAL_BAUD 9600
#define GPS_BAUD 9600
#define N_FLOATS 4

elapsedMillis timeElapsed;
Ublox M8_Gps;

unsigned int timeout = 5000; // 5s timeout
// Altitude - Latitude - Longitude - N Satellites
double gpsArray[N_FLOATS] = {0, 0, 0, 0};

void setup() {
   Serial.begin(SERIAL_BAUD);
   Serial1.begin(GPS_BAUD);
   Serial2.begin(9600);
}

void loop() {
   if(!Serial1.available())
    return;

  while(Serial1.available()){
        char c = Serial1.read();
         if (M8_Gps.encode(c)) {
          gpsArray[0] = M8_Gps.altitude;
          gpsArray[1] = M8_Gps.latitude;
          gpsArray[2] = M8_Gps.longitude; 
          gpsArray[3] = M8_Gps.sats_in_use;
        }
  }
  for(byte i = 0; i < N_FLOATS; i++) {
    Serial.print(gpsArray[i], 6);Serial.print(" ");
  }
  Serial.println("");

         /* gpsArray[0] = 1000;
          gpsArray[1] = 1.123456;
          gpsArray[2] = 133.135555; 
          gpsArray[3] = 7;
*/
          
  String transmit = "$";
  transmit.concat(String(gpsArray[1], 6));
  transmit.concat('#');
  transmit.concat(String(gpsArray[2], 6));
  transmit.concat('#');
  transmit.concat(String(gpsArray[3], 6));
  transmit.concat('^');
  
  if (timeElapsed > timeout)
  {
    Serial.print("Transmit");
    Serial2.write(transmit.c_str(), transmit.length());
    timeElapsed = 0;
  }
}
