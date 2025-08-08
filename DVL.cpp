//This file is responsible for using all the methods outlined in the DVL_SIM class in the header file

#include <DVL.h>

//Firstly, we create the constructor class
DVL_SIM::DVL_SIM(IPAddress ip, unsigned int port){
  ip = teensy;
  port = udpPort;
  vx = vy = vz = 0.0f;
  d1 = d2 = d3 = d4 = 5.0f; //just for basic initialisation
}
