//This file is responsible for using all the methods outlined in the DVL_SIM class in the header file

#include <DVL.h>

//Firstly, we create the constructor class
DVL_SIM::DVL_SIM(IPAddress ip, unsigned int port){
  ip = teensy;
  port = udpPort;
  vx = vy = vz = 0.0f;
  d1 = d2 = d3 = d4 = 5.0f; //just for basic initialisation
}

//Basic start for ethernet communication - sets up the DVL to send udp packets to the teensy
void DVL_SIM::begin(){
  Ethernet.begin(teensy);
  udp.begin(updPort);
}

void DVL_SIM::init(){
  vx = randomVelocity();
  vy = randomVelocity();
  vz = randomVelocity();

  d1 = randomDistance();
  d2 = randomDistance();
  d3 = randomDistance();
  d4 = randomDistance();

  String final_text = finalSentence();

  //Send the udp packets (figuring out how to code this right now) (All the above data can be sent through udp packets to simulate a dvl)

  
}

//Delegation Starts
//Zain
void DVL_SIM::finalSentence(){
  string s = "";
  //we can concatenate everythig to this string
  s += "
}


