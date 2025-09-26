# Khadra – WRO Future Engineers Project  
**Team Triobotics**

## Introduction  
This repository contains all engineering materials for our project **Khadra**, a self-driven vehicle model built by **Team Triobotics** to participate in the **WRO Future Engineers competition 2025**.  
Our main objective was to design, simulate, and implement a self-driving robotic vehicle that can navigate autonomously using sensors and control algorithms.

## Our Journey  
We started our project by exploring **microcontrollers** and learning how to connect and use **different sensors**. From there, we gradually moved on to understanding the **steering mechanism** using a **servo motor**.  

At the beginning, we simulated all the electronic connections and tested our code using **Tinkercad**, which allowed us to safely experiment with circuits and Arduino programming. After verifying the simulations, we transitioned to building the physical model of the robot.  

The final body of our robot was designed and fabricated using **3D printing**:  
https://grabcad.com/library/3d-printed-rc-car-1

This step-by-step process helped us combine electronics, coding, and mechanical design into a working autonomous vehicle.

## Repository Structure  
This repository follows the official WRO Future Engineers template.  

- **t-photos** → Contains 2 photos of the team (official + funny photo)  
- **v-photos** → Contains 6 photos of the vehicle (from every side, top, and bottom)  
- **video** → Contains `video.md` with the link to the driving demonstration video  
- **schemes** → Contains schematic diagrams (JPEG, PNG, PDF) of electronic components and motor wiring  
- **src** → Contains the Arduino C++ source code for the vehicle’s control software  
- **models** → Contains files for 3D printing and laser cutting of vehicle parts  


## Hardware Used  
- **Microcontroller**: Arduino Uno  
- **Sensors**: Ultrasonic sensor, Color sensor  
- **Actuators**: Servo motor (for steering) + DC motors for movement  
- **Other components**: chassis, wheels, battery   

## Software Used  
- **Arduino IDE** → For programming in Arduino C 
- **Tinkercad** → For simulating circuits and testing code  
- **3D Printing tools** → For designing and producing the robot body  

## How to Build and Run  
1. Connect the sensors and motors according to the wiring diagrams in the **schemes** folder.  
2. Upload the Arduino C++ code from the **src** directory using Arduino IDE.  
3. Place the 3D-printed parts together to assemble the body of the robot.  
4. Test the robot in a safe environment, starting with basic movement and then activating autonomous mode.  

## Team  
- **Team Name**: Triobotics  
- **Robot Name**: Greenery  

We are a passionate team of students exploring the fields of electronics, coding, and robotics through this exciting challenge.  

## Acknowledgments  
We would like to thank **WRO organizers**, our mentors, and all those who supported us in this journey.  
