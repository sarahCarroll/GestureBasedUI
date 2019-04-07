#include <Servo.h>
#include <MyoController.h>
#include <SoftwareSerial.h>

//The pin connections in the arduino board
#define WAVE_PIN 9
#define FINGERSSPREAD_PIN 11
#define LIGHTS_PIN 5

//bluetooth pins
#define rx 0
#define tx 1

String inData;
SoftwareSerial BLE(tx, rx);

// declaring the myoController function from the libraries
MyoController myo = MyoController();

//servo library which allows arduino to control rc motors
Servo serv;
Servo servo1;

void setup() {
  serv.attach(11);
  servo1.attach(9);

  //recognise the output of the pins
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(rx, INPUT);
  pinMode(tx, OUTPUT);
  BLE.begin(9600);

  pinMode(LIGHTS_PIN, OUTPUT);
  pinMode(WAVE_PIN, OUTPUT);
  pinMode(FINGERSSPREAD_PIN, OUTPUT);

  Serial.begin(9600);
  myo.initMyo();
  
}

void loop(){
   myo.updatePose();
   switch ( myo.getCurrentPose() ) {
    case waveIn:
    //servo will turn car left 30 degrees
      digitalWrite(WAVE_PIN,HIGH);
      digitalWrite(9, HIGH);
      servo1.write(30);
      break;
    case waveOut:
    //Servo will turn car right 150 degrees
      digitalWrite(WAVE_PIN,HIGH);
      digitalWrite(9, HIGH);
      servo1.write(150);
      break;
    case fingersSpread:
    //Will drive the car forward as is connected to motor pin
     digitalWrite(FINGERSSPREAD_PIN,HIGH);
     digitalWrite(11, HIGH);
      break;
    case doubleTap:
    //LED Lights turn on from pin 5
    if(digitalRead(5) == LOW){
     digitalWrite(LIGHTS_PIN,HIGH);
     digitalWrite(5, HIGH);
    }else {
      digitalWrite(LIGHTS_PIN,LOW);
      digitalWrite(5, LOW);
    }
    break;
    case fist:
    //CAR GOES STRAIGHT as it is 90 degrees
     digitalWrite(WAVE_PIN,HIGH);
     digitalWrite(9, HIGH);
     servo1.write(90);
      break;

   } 
   delay(1);
}
