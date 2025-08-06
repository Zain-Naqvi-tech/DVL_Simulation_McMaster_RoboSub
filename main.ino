//Code for DVL Simulation
/*IMU & Navigation:
- Nortek Nucleus 1000 DVL – Doppler Velocity Log for underwater localization
    - BUILT-IN: Sub-Conn cable (w/ DVL) – Waterproof interface
    - BUILT-IN: Sub-Conn to Ethernet adapter board – For DVL communication */

//Check out this link for ethernet setup information: https://www.pjrc.com/store/ethernet_kit.html (hardware setup)

//(ROUGH COMMENT) Reference for some part of the code right now - Arduino Docs: https://docs.arduino.cc/libraries/ethernet/

#include <NativeEthernet.h> //Used for communication with the teensy 4.1 - https://github.com/vjmuzik/NativeEthernet
#include <EthernetUdp.h> //UDP is the communication protocol used by the DVL - the DVL sends its data as UDP packets. 

IPAddress ip(); //Custom IP for the Teensy (must feed the 4 numbers)

char packetBuffer[250]; //buffer to hold packet (size of the packet (array of char) depends on the expected size of the packet)

EthernetUDP udp; //create an instance of ethernet udp object using the EthernetUDP from the library - communication protocol 
unsigned int port; //port from the dvl - teensy will listen to the data sent by the dvl on this port

void setup() {
    Serial.begin(9600); //start the serial monitor 
    Ethernet.begin(ip); //initialises the ethernet hardware
    udp.begin(port); //the teensy starts processing incoming data (UDP Messages)
}

void loop() {
    //Need to add a way to show the data sent in from the dvl using ethernet protocols (some snippets taken from arduino forum)
    int packetSize = udp.parsePacket();
    if packetSize() {
        // if there is a response from udp.parsePacket() 
        
    }
}

//Need a way to process all that data into json and get it ready for proper display - might need it for the dashboard (or better testing)



