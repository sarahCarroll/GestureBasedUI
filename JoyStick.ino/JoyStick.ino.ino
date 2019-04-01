#include <Servo.h> 
 
Servo servo1; // Steering Servo
Servo servo2; // Speed Servo

int joyX = 0; // Steering Servo
int joyY = 1; // Speed Servo

int joyVal;
 
void setup() 
{ 
 servo1.attach (9);    // Steering Servo didgital pin
 servo2.attach (11);   // Speed Servo didgital pin
} 

void loop()

{
 
  // Steering Servo
  // mapped from pot 0-1023 to 1-180 so its a value in degrees but split in the middle to get left and right, re-centre
 {
 joyVal = analogRead (joyX);              
 
 if (joyX < 480)
 {
 joyVal = map (joyVal, 0, 511, 50, 90);    // right caibrated to not over reach to the right
 servo1.write (joyVal);
 delay (5);
 }
 else if (joyX > 530)
 {
 joyVal = map (joyVal, 513, 1023, 90, 180); //left caibrated to not over reach to the left
 servo1.write (joyVal);
 delay (5);
 }
}
 
 
 // Speed servo 
 
 
 //joyVal = analogRead (joyY);               
 //joyVal = map (joyVal, 530, 1023, 0, 255);   // once the joystick is moved forward past 530 its maps the motor speed form 0 to 255
 //servo1.write (joyVal);
 
 //delay (5);
}