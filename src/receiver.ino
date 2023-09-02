#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <AFMotor.h>
#include <Servo.h> 

// Servo Motor setup with L293D Shield
Servo myServo; 
int servoPosition = 0;

// DC Motors setup with L293D Shield
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
#define motorSpeed 200

// NRF24L01 Setup
RF24 radio(35, 34); // CE and CSN port declaration respectively. Can use any digital pin on the Arduino
const byte radioAddress[6] = "00001"; // Byte Address for the RF Module. Must be the same on the transmitting end

int receivedX, receivedY; // Initialize the receivedX and receivedY variables to store the received data
int joystickData[2]; // Joystick Array for X and Y axis data

void setup() {
  Serial.begin(9600);

  // DC Motors and Servo Initialization
  motor1.setSpeed(motorSpeed);
  motor2.setSpeed(motorSpeed);
  myServo.attach(10);

  // Receiving RF Module Initialization
  radio.begin(); // Start RF Module Comms
  radio.openReadingPipe(0, radioAddress); // Set which channel (address) to communicate with 
  radio.setPALevel(RF24_PA_MAX);     // Set power level for RF Module (Min for low power, short distance; Max for high power, long distance).
  radio.startListening();            // Start Receiving
}

void loop() {
  if (radio.available()) { // Searching for incoming data
    radio.read(&joystickData, sizeof(joystickData)); // Read incoming data
    receivedX = joystickData[0]; // Store index 0 in the incoming array into receivedX variable
    receivedY = joystickData[1]; // Store index 1 in the incoming array into receivedY variable

    int mappedX = map(receivedX, 0, 1023, 10, 170); // Scale receivedX data for precise servo movement (beta)

    Serial.println(receivedX); // For testing purpose; ensure correct incoming data

    // These series of conditional statements are based on the receivedX and receivedY coordinate system of the PS2 Joystick
    // receivedX ranges from 0 to 1023 (Left to Right)
    // receivedY ranges from 0 to 2023 (Up to Down)

    if (receivedY >= 530) { // Backwards Condition
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
    } else if (receivedY <= 495) { // Forward Condition
      motor1.run(FORWARD);
      motor2.run(FORWARD);
    } else if (receivedX < 30) { // Left Turn Condition
      myServo.write(0);
      motor1.run(FORWARD);
      motor2.run(FORWARD);
    } else if (receivedX > 1000) { // Right Condition 
      myServo.write(180);
      motor1.run(FORWARD);
      motor2.run(FORWARD);
    } else { // If joystick is in the neutral position, Motors are stopped and servo points straight
      myServo.write(90);
      motor1.run(RELEASE);
      motor2.run(RELEASE);
    }
  }
}
