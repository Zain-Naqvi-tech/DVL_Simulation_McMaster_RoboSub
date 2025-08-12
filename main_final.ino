
#include <DVL_SIM.h> //import our library header

IPAdress teensy(1,2,3,4); //pre-built IP for testing purposes (explaination in main.ino file)
unsigned int udpPort = 12345;

DVL_SIM dvl(teensy, updPort); //create an instance of the class

void setup() {
  Serial.begin(9600);
  
}
