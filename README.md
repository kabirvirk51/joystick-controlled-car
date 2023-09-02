# joystick-controlled-car
# Arduino Radio-Controlled Car

![Arduino Radio-Controlled Car](car_image.jpg)

**Disclaimer:** This personal project was undertaken to create a remote-controlled car using Arduinos and RF modules. The project aims to control a car wirelessly, potentially adapting it for use in various hobby RC cars.

## Table of Contents
- [Parts List](#parts-list)
- [Current Build](#current-build)
  - [Transmitting End](#transmitting-end)
  - [Receiving End](#receiving-end)
- [YouTube Playlist](#youtube-playlist)
- [Future Plans](#future-plans)

## Parts List

Here is the list of components used in the project:

1. PiCar-V Chassis, Motors, and Wheels
   - [Purchase Link](https://www.sunfounder.com/products/smart-video-car)

2. Two Lithium Polymer batteries rated at 3.7V 2000 mAh
   - [Purchase Link](https://www.sparkfun.com/products/13855)

3. L293D Motor Shield for Arduino
   - [Purchase Link](https://www.sunfounder.com/products/l293d-motor-drive-shield?_pos=1&_sid=4cbf1d2a0&_ss=r)

4. Half-Size Breadboard
5. Two NRF24L01 Transceiver Modules
6. Arduino Mega 2560
7. Arduino Nano
8. PS2 Joystick
9. One Servo Motor
10. Soldering Equipment (Necessary for 1 pin)

## Current Build

![Current Build](current_build.jpg)

### Transmitting End

The transmitting end of the project utilizes an Arduino Nano connected to a PS2 joystick. The Nano sends joystick data, including X and Y axis positions, to an Arduino Mega using a pair of NRF24L01 radio modules. 

The joystick's X and Y pins are connected to two Analog In ports on the Nano, which convert the analog data into digital format. This data is then transmitted to the RF receiver on the Arduino Mega.

### Receiving End

The Arduino Mega on the receiving end interprets the X and Y axis data and uses conditional statements to control the car's movement. The L293D shield is employed to connect two DC motors and a servo motor, enabling control over the car's wheels and servo mechanism.

## YouTube Playlist

I will be creating a series of videos to provide more in-depth explanations of the project and demonstrate its functionality. Stay tuned for updates!

## Future Plans

Here are some plans for future enhancements to the project:

1. Design a custom PCB board for the joystick controller to improve handheld control and portability.
2. Integrate 18650 batteries for extended power supply.
3. Implement a simple camera attached to servo motors, allowing for remote-controlled camera movements using a second joystick.

Feel free to explore this project, and if you have any questions or suggestions, please don't hesitate to reach out.

## License

This project is released under the [MIT License](LICENSE).

---

Thank you for checking out the Arduino Radio-Controlled Car project!

