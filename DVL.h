//This file is responsible for faking data from a DVL - HEADER FILE
//We are using a Nortek Nucleus 1000 as our DVL
// https://support.nortekgroup.com/hc/en-us/article_attachments/17223428270620 (All the required formats and display elements are taken from this reference) (each data type has also been taken from here) (Chapter 8.11 provides us with most of the required information)

#ifndef DVL_H
#define DVL_H

#include <NativeEthernet.h>
#include <EthernetUdp.h>

//Creating a DVL class for better organisation - all online resources have suggested the use of classes due to their private and public seperation which allows for a more organised and cleaner code
class DVL_SIM {
public:
  DVL_SIM(IPAddress ip, unsigned int port);

  void begin();
  void init();

private:
  IPAddress teensy;
  unsigned int udpPort;
  EthernetUDP udp;

  float randomVelocity(); //random vx, vy, vz - need to just output a random velocity from a negative to positie range - this functions can be reused for vx, vy and vz seperately. 
  float randomDistance(); //beam ranges (m)
  String timeStamp(); //.
  float delay(); //another random time in s - Time from the center of the echo of the cell, which estimates the water track velocity, to the time indicated by timestamp

  float FOM(); //This returns a randomized figure of merit - quantifies the performance
  String checksum(); //many online resources suggest using this as another element in the simulation 
  float temp(); //random temperature (degree Celcius)
  float pressure(); //random pressure (Bar)
  float sound_velocity(): //random sound velocity (m/s)
  String finalSentence();
  
  float vx, vy, vz; 
  float d1, d2, d3, d4; //all beam ranges (4)
  float temperature;
  float bar; //pressure variable - assigned a value using the function float pressure(); 
  

};

#endif




