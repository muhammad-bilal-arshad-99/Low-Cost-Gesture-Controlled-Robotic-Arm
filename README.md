## About the Project:

I built this robotic arm during summer vacations of 2026. My previous concrete models and machine learning regression model sparked my interest in the field of robotics. While building my concrete bridge, I began wondering how structures could be automated. That curiosity led me to explore robotics, and I decided to build a gesture-controlled robotic arm as my first robotics project. I had only seen capacitors and resistors in textbooks, never in real life.

## How it Works:

The arm reads the tilt of my hand using an MPU6050 accelerometer and maps that motion to two servo motors. One servo rotates the entire arm (base), while the second lifts or lowers the arm (shoulder). The end‑effector is a hook, allowing the arm to pick up and move lightweight objects. The system runs on an Arduino Nano, and the servos are powered separately to avoid overloading the board.

## Components Used:

Arduino Nano

MPU-6050

3 x Sg90 Servo motors 

Breadboard 

Jumper Wires

100uF Capacitor

Power Supply 

## Skills & Concepts I Learned:

Technical Skills:

Arduino Programming (C++)

Sensor Integration

Servo Motor Control

Engineering Concepts:

Mechanical Design

Torque & Lever Mechanics

Mechanical Resonance

## Challenges:

My very first shot at soldering the MPU-6050 pins turned into a complete mess. I accidentally bridged the power connections, and the board's mini LED instantly went dark. I couldn’t afford a new replacement sensor, but that day I felt an unexpected satisfaction. I made a mistake and knew exactly which connection was shorting. By the next day, I had re-soldered every pin, holding my breath until the mini LED suddenly blinked open. I can't even describe the absolute rush of seeing it work. I am driven to pursue this field not because I am already an expert, but because I have learned how to fail. I bought three SG90 servo motors to make the arm but on the third day of making it, something unexpected occurred — The servo attached on the shoulder of the arm began grinding and producing high-pitched sounds. The arm drooped, completely dead. I sat down and crunched the torque math: the small servo was pushing only 1.2 Kg-cm, but my extended mechanical setup practically demanded double that load. Giving up wasn't an option, so I made a rough engineering trade-off: I sacrificed the gripper servo—losing the hand but saving the arm’s lifting ability. A one-armed crane is still a crane, I told myself. This setback forced me to calculate lever length and counter-weights. However, when reassembled, the turntable vibrated wildly until I applied gentle fingertip pressure to the shoulder servo. The vibrations vanished. I realized they weren’t a component defect, but mechanical resonance, which can be tamed by adding energy-absorbing material or shifting the physical mass. Deep-diving into Google forums later, I was blown away to find out that civil engineers scale up this exact phenomenon to stop massive skyscrapers from snapping during earthquakes. Tinkering with the arm also forced me into the software side, teaching myself to write raw C++ sketches to smooth out the servo jitter.

## Why this project matters to me

This project taught me that engineering is rarely about getting everything right on the first attempt. Building the arm with limited resources forced me to think creatively, solve unexpected mechanical problems, and learn through experimentation. Looking back, the challenges were more valuable than the finished prototype because they changed how I approach engineering problems.

## Furture Improvements If I revisit this project:

Replace the SG90 servo motors with higher-torque servo motors to increase the arm's lifting capacity.

Design and manufacture a stronger chassis using CAD software and 3D printing. 

Improve the balance of the arm by optimizing the weight distribution.

Increase the arm's degrees of freedom for more natural movement.

Add a functional gripper capable of picking up lightweight objects.

## Watch working of this project here:
https://www.youtube.com/shorts/DYNUtzJnawM
