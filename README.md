# Hand-Gesture Activated Lock
## Overview
This device is an arduino based system that allows for a user to set a password and show hand digits to a camera in order to unlock a digital lock. This system demostrates the capability of computer vision in modern security devices. Through Mediapipe hand-tracking this system could be modified to use non-traditional gestures for increased security.

## Function
* Holds a 4 digit password
* Checks to see if password is correct
* After 3 incorrect passwords -> locked out
* Use your hand to enter digits (1-4)
* 5 fingers -> clears entry
* Closed fist -> checks to see if password is correct

## Code
Python
* OpenCV for computer vision
* MediaPipe for hand tracking
* Outputs data using Serial to arduino

Arduino
* Holds password/checks to see if correct (strcmp)
* Keeps track of attempts
* Takes Serial data as input
* Outputs to LEDs and display

## Video Showcase
https://github.com/user-attachments/assets/44906f44-4e43-4a4d-b9e2-b76adf374114

## Tinkercad Prototype

<img width="1291" height="1156" alt="tinker" src="https://github.com/user-attachments/assets/6109892a-6ed0-4533-a047-23ae17f7de2a" />

## Breadboard Prototype

![bread](https://github.com/user-attachments/assets/ffc295d7-250d-42d3-9922-bf7327e4670d)

## Soldered Design

![sold](https://github.com/user-attachments/assets/59128efb-2222-43f8-ae28-9a7a1f539997)
![solduh](https://github.com/user-attachments/assets/e733d67d-7440-44d0-964d-69540a4de37d)
