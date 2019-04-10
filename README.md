# Gesture Based User Interface

This project is a 4th year assignment for the module Gesture Based UI Development.

Author: Abigail Culkin and Sarah Carroll

## How to Run the application

1. In order to run this application. The user must have arduino desktop application.This is downloadable from the windows store.
2. Load the CarController.ino file (found tin Handgestures folder) into the arduino desktop application. 
3. Compile and run the code.(this sends the code directly to the arduino). MAke sure it is running off the correct port. In our case port com06.
4. Connect the MYO armband to the laptop following steps in "Gesture Based UI Project.odt".
5. Run MyoDuino executable application.(found in Handgestures folder)
6. When running the MyoDuino application the user to promted to pick a port this must be Com06.(same as arduino port).



## Video Demo
Here is a video of this project in action. This was a requirement for submission. This must be downloaded locally to your machine.
[video](https://github.com/sarahCarroll/GestureBasedUI/blob/master/VideoDemo.mp4)

## Coding Syle

For our project we have used the programming language Ino. This is equivalent to Cpp. The arduino files are .ino.

The CarController folder is the folder that contains ino file we coded.
The numbers are the pins that are connected to the arduino board in the example below.
```
#define WAVE_PIN 9
#define FINGERSSPREAD_PIN 11
#define LIGHTS_PIN 5

```
An example of our switch statement which controls the car moving by the users gestures and the degrees the car will turn.
```
switch ( myo.getCurrentPose() ) {
    case waveIn:
    //servo will turn car left 30 degrees
      digitalWrite(WAVE_PIN,HIGH);
      digitalWrite(9, HIGH);
      servo1.write(30);
      break;
```
The libraries folder contains cpp files that references the Myo gestures so the arduino can recognise them and you can see in the application window which gesture you preformed.
```
if(msgChar.indexOf("rest")>=0)
	{
		current_pose_=rest;
	}
```
```
enum Poses{
	rest,
	fist,
	waveIn,
	waveOut,
	fingersSpread,
	doubleTap,
	unknown
};
```
## References and gesture description
See "Gesture Based UI Project.odt".
