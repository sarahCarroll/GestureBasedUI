#include <Servo.h> 
 
Servo servo1; // Steering Servo
Servo servo2; // Speed Servo

int joyX = 0; // Steering Servo
int joyY = 1; // Speed Servo

int joyVal;
 
void setup() 
{ 
 servo1.attach (9);    // Steering Servo
 servo2.attach (10);   // Speed Servo
} 

void loop()

{
 joyVal = analogRead (joyX);
 joyVal = map (joyVal, 0, 1023, 0, 180); 
 servo1.write (joyVal);
 
 joyVal = analogRead (joyY);
 servo1.write (joyVal);
 
 delay (15);
}
