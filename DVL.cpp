//This file is responsible for using all the methods outlined in the DVL_SIM class in the header file

#include <DVL.h>

//Firstly, we create the constructor class
DVL_SIM::DVL_SIM(IPAddress ip, unsigned int port){
  teensy = ip;
  udpPort = port;
  vx = vy = vz = 0.0f;
  d1 = d2 = d3 = d4 = 5.0f; //just for basic initialisation
  temperature = 0;
  bar = 0;
}

//Basic start for ethernet communication - sets up the DVL to send udp packets to the teensy
void DVL_SIM::begin(){
  Ethernet.begin(teensy);
  udp.begin(udpPort);
}

void DVL_SIM::init(){
  vx = randomVelocity();
  vy = randomVelocity();
  vz = randomVelocity();

  d1 = randomDistance();
  d2 = randomDistance();
  d3 = randomDistance();
  d4 = randomDistance();

  temperature = temp();
  bar = pressure();

  CS = checksum();
  
  String final_text = finalSentence();

  //Send the udp packets (figuring out how to code this right now) (sent through udp packets to simulate a dvl)
  udp.beginPacket(udp.remoteIP(), udp.remotePort() > 0 ? udp.remotePort() : udpPort);
  udp.write(sentence.c_str());
  udp.endPacket();
  
}

void DVL_SIM::finalSentence(){
  dt1 = delay();
  dt2 = delay();
  FOM_s = FOM();
  String s = "";
  //we can concatenate everythig to this string
  s += "vx = " + String(vx, 2);
  s += "vy = " + String(vy, 2);
  s += "vz = " + String(vz, 2);
  s += "d1 = " + String(d1, 2);
  s += "d2 = " + String(d2, 2;
  s += "d3 = " + String(d3, 2);
  s += "d4 = " + String(d4, 2);
  s += "Temp = " + String(temperature, 2);
  s += "Pressure = " + String(bar, 2);
  s += "Sound Velocity = " + String();
  s += "Time = " + String(timeStamp(), 2);
  s += "dt1 = " + String(dt1, 2);
  s += "dt2 = " + String(dt2, 2);
  s += "FOM = " + String(FOM_s, 2);
  s += "Checksum = " + String(CS, 2)

  //might need to clean the output based on whhat we get once all the functions are done
  
}

float DVL_SIM::randomVelocity(){ //random velocity in m/s
  x = (float)random(-5000,5000) / 1000.0f; //using the arduino random() function in this case
  return x
}

float DVL_SIM::randomDistance(){ //random distance in m
  return ((float)random(1,750) / 10.0f);
}

float DVL_SIM::tmep(){ //random temperature in degrees celcius
  return ((float)random(-4,40));
}

float DVL_SIM::pressure(){ //random pressure in bar
  return ((float)random(100)); 
}

float DVL_SIM::delay(){
  return ((float)random(-2000,2000));
} 

float DVL_SIM::FOM(){ //Figure of Metric - Not so sure about an output from this function, but many sources have suggested it
  return ((float)random(50));
}

float DVL_SIM::timeStamp(){
  return ((float)random(0,30));
}

float DVL_SIM::sound_velocity(){
  //basic UNESCO sound velocuty formula. 
  return 1449.0f + 4.6f * temperature - 0.055f * temperature * temperature + 0.00029f * temperature * temperature * temperature + 0.16f * bar;
}

float DVL_SIM::checksum(){
  //Figuring it out - need to use a pre-built formula like the sound_velocity one
  
}

