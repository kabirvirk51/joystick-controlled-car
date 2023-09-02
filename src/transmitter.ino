#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// NRF24L01 Setup
RF24 radio(7, 8); // CE and CSN port declaration respectively. Can use any digital pin on the Arduino
const byte transmitterAddress[6] = "00001"; // Byte Address for the RF Module. Must be the same on the receiving end

int joystickData[2]; // Joystick Array for X and Y axis data

void setup() {
  Serial.begin(9600);

  // Transmitting RF Module Initialization
  radio.begin(); // Start RF Module Comms
  radio.openWritingPipe(transmitterAddress); // Set which channel (address) to communicate with
  radio.setPALevel(RF24_PA_MAX); // Set power level for RF Module (Min for low power, short distance; Max for high power, long distance)
  radio.stopListening(); // Start transmission
}

void loop() {
  // Read X and Y axis data from the joystick
  joystickData[0] = analogRead(A6); // Store X axis data received from joystick into array index 0
  joystickData[1] = analogRead(A7); // Store Y axis data received from joystick into array index 1
  
  // Transmit joystick data to the receiver module
  radio.write(&joystickData, sizeof(joystickData));
}
