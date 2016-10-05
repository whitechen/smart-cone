{\rtf1\ansi\ansicpg1252\cocoartf1404\cocoasubrtf470
{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 // This #include statement was automatically added by the Particle IDE.\
//#include "Ublox.h"\
//#include "cellular_hal.h"\
\
#define SERIAL_BAUD 9600\
#define RX_BAUD 9600\
#define N_FLOATS 4\
\
//Ublox M8_Gps;\
// Altitude - Latitude - Longitude - N Satellites\
double gpsArray[N_FLOATS] = \{0, 0, 0, 0\};\
\
String officer;\
int coneId = 0;\
double latitude = 0;\
double longitude = 0;\
double numSat = 0;\
double lastTime = 0;\
int completed = 0;\
\
//STARTUP(cellular_credentials_set("e-ideas", "", "", NULL));\
\
void setup()\
\{\
  Serial.begin(SERIAL_BAUD);\
  Serial1.begin(RX_BAUD);\
  \
  // variable name max length is 12 characters long\
  Particle.variable("officer", officer);\
  Particle.variable("coneId", coneId);\
  Particle.variable("latitude", latitude);\
  Particle.variable("longitude", longitude);\
  Particle.variable("numSat", numSat);\
  //Particle.variable("completed", completed);\
  //Particle.variable("lastTime", lastTime);\
  \
  officer = "Tester2";\
  coneId = 2;\
\}\
\
void loop()\
\{\
   if(!Serial1.available())\
		return;\
\
  while(Serial1.available())\{\
        char c = Serial1.read();\
        Serial.print(c);\
        if (c == '$') \{\
            String element = "";\
            int i = 1;\
            do \{\
                delay(2);\
                c = Serial1.read();\
                Serial.print(c);\
                if (c == '#' || c == '^') \{\
                    gpsArray[i++] = atof(element.c_str());\
                    element = "";\
                    if (i > 3) \{\
                        i = 3;\
                    \}\
                \} else \{\
                    element.concat(c);\
                \}\
            \} while (c != '^');\
        \}\
  latitude = gpsArray[1];\
  longitude = gpsArray[2];\
  numSat = gpsArray[3];\
  \
  delay(30000);\
  //lastTime = Time.now();\
  //completed = 0;\
  \}\
\}}