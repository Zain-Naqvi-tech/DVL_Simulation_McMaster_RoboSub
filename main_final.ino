
#include <DVL.h> //import our library header

IPAdress teensy(1,2,3,4); //pre-built IP for testing purposes (explaination in main.ino file)
unsigned int udpPort = 12345;

DVL_SIM dvl(teensy, updPort); //create an instance of the class made in the DVL.h file

void setup() {
  Serial.begin(9600);
  dvl.begin(); //starts our instance of DVL_SIM
}

void loop () {
  dvl.init(); //initializes the dvl class and calls on all the functions defined inside the class - allows for all functions to run and display outputs as needed
  delay(1000); //allows the program some time before initializing it again and getting new values from the functions. 
}
