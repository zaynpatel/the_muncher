---
layout: post
title: Software Design
author: "Zayn Patel"
date: December 15, 2023
category: resources
permalink: /softdes
---
## Design Goals
Firmware design on the rover can be divided into two component halves: a low-level driver to operate the soil sampler, a high level Arduino script to interact with the soil sampler, and parsing code which acted as a passthrough between a JS front-end application, Jetson Nano, and ESP32s. 

![Frontend App](https://zaynpatel.github.io/the_muncher//assets/img/frontend_App.png)

Our team added other features like AprilTag Detection so the rover could drive autonomously, a Turret to dispense seeds in Parcel B, and a text to speech/speech to text pipeline so humans could talk to the robot. 

[Our code](https://github.com/olincollege/The-MuNCHER) used many external dependencies including:
- socket
- serial
- apriltag library
- OpenCV library
- gstreamer pipeline
- numpy 
 
## Implemented Solutions, Decision Explanations, and Iterations

#### Soil Sampler Code
The code works where commands are sent from the Jetson Nano that instructs the soil sampler to pick up a cartridge, retrieve a soil sample and return the cartridge to the same slot on the plate. The Jetson will send one digit that specifies which slot to pick up and another as an emergency abort message. The code orders commands between limit switches, lead screws, steppers and drill speed in a specified order to achieve the soil sampling capabilities. One issue that we faced was getting the stepper motor that controlled the cartridge plate to rotate to where the cartridges lay directly under the drill. This took a bit of guesswork and checking in order to get it to work properly.

#### App/ UI Code
The app is a simple one-page Electron site that holds the key controls for the app including remote control drive modes (w, a, s, d), live stream from the USB camera, robot status (whether it’s connected to battery voltage or not), sampler controls (what sample it’s currently getting and whether or not it’s taking a sample). 

#### Jetson Code
The Jetson serves as a passthrough module for commands from the JS application to send through the Jetson and from the Jetson commands go through the ESP32. In addition, the Jetson was used to run computer vision pipelines so we could detect apriltags and autonomously drive. 

#### ESP32 Code 
We have two ESP32 that share io functionality and send and receive messages to and from the Jetson Nano. ESP32 A does the stepper motor, limit switch, drill and servos commands. ESP32 B does the drive commands and LED’s. The ESP32 are dual-core which allow USB communications as well as IO commands simultaneously. The reason for two ESP32 is in order to improve processing speed and IO capabilities. 

#### Camera System
We have two cameras connected to a jetson – one camera is an FPV camera that connects to a VR headset and the other camera is USB connected and captures real-time video and detects apriltags. The USB camera was calibrated to detect apriltags using the apriltag python library with the detection_pose function. Configuring this gave us focal length and optical centers so the camera would focus and detect apriltags from multiple angles. We decided to integrate the apriltags so our rover could drive autonomously. The FPV camera was simpler to configure and enables us to drive using a first person view on the camera. 

## Considerations for Future Work
For future work we would like to implement a LLM into The MuNCHER that is able to provide answers in a human-like way to any prompted question. Also, we would like to add low-level embodied intelligence which goes above april-tag autonomy and allows us to do path following and object detection / avoidance.
