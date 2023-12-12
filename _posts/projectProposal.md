---
layout: post
title: "PIE Project Proposal"
author: "Kenta, Ian, Matt, Mihir, Zayn"
categories: documentation
tags: [documentation,sample]
image: rover_concept.png
permalink: /proposal
---

The MuNCHER (**Multidirectionally Navigable and Computationally Helmed Exploratory Rover**) is a: 4-wheel, autonomous, first person VR drive, talking Mars Rover inspired robot built by [students at the Olin College of Engineering]().

When we started [brainstorming]() this project on October 16, 2023 we wanted to create a robust robotic vehicle that could navigate [Parcel B](), the forest behind Olin College, and collect multiple soil samples using a retrofitted drill and lazy susan storage mechanism. 


"Share more about how the project was broken up -- 6 week sprints, share a calendar image that shows this, will be cooler, can even sketch goal v. accomplished"

### Demo media

#### Final Demo Video after 6 weeks


#### Final Demo Images after 6 weeks

### Table breakdown of what we accomplished in each sprint

| Sprint | Mechanical                                        | Electrical                                         | Software                                                                                          |
|--------|---------------------------------------------------|----------------------------------------------------|---------------------------------------------------------------------------------------------------|
| 1      | First version of drivetrain and suspension modules designed and fabricated. First version of the soil sampler design complete. | Battery wiring, motor controller sealing and wires attached to ESP32 | Arduino code so we can control and move the robot around.                                        |
| 2      | Redesign and fabrication of drivetrain and suspension complete. Soil sampler design finalized and system fabricated. | Wired Jetson, ESP32, CNC Motor Shield, Stepper motors, batteries onto the rover. | Remote controlled the rover through a combination of keyboard inputs on a JS application to a Jetson Nano to one of our ESP32’s. |
| 3      | Final soil sampling mechanical design revisions. Added body panels as electrical enclosures. Mechanical design for soil sampling turret. | Integrated soil sampling on linear slides, added a turret based seed dispenser to the side of the rover, an FPV camera/VR headset, USB Camera, Attached blue LEDs to the bottom of the rover. | Wrote a low level driver for the soil sampling drill, write high level code to communicate with the soil sampler, calibrated and detected april tags with USB camera, got the rover to talk using an LLM. |



Feel free to check out <a href="https://github.com/LeNPaul/jekyll-starter-kit" target="_blank">the page</a>, where you’ll find what we finished in the first two weeks.