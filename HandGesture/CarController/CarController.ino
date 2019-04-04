#include <Servo.h>
#include <MyoController.h>
#include <SoftwareSerial.h>

#define RxD 2
#define TxD 3

#define WAVE_PIN 9
#define FINGERSSPREAD_PIN 11
#define LIGHTS_PIN 5

String inData;
SoftwareSerial BLE(RxD,TxD);

MyoController myo = MyoController();
Servo serv;
Servo servo1;

void setup() {
  serv.attach(11);
  servo1.attach(9);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(5, OUTPUT);

 pinMode(RxD, INPUT);
pinMode(TxD, OUTPUT);

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
      digitalWrite(WAVE_PIN,HIGH);
      digitalWrite(9, HIGH);
      servo1.write(30);
      break;
    case waveOut:
      digitalWrite(WAVE_PIN,HIGH);
      digitalWrite(9, HIGH);
      servo1.write(150);
      break;
    case fingersSpread:
     digitalWrite(FINGERSSPREAD_PIN,HIGH);
     digitalWrite(11, HIGH);
      break;
    case doubleTap:
    //LED Lights
    if(digitalRead(5) == LOW){
     digitalWrite(LIGHTS_PIN,HIGH);
     digitalWrite(5, HIGH);
    }else {
      digitalWrite(LIGHTS_PIN,LOW);
      digitalWrite(5, LOW);
    }
    break;
    case fist:
    //CAR GOES STRAIGHT
     digitalWrite(WAVE_PIN,HIGH);
     digitalWrite(9, HIGH);
     servo1.write(90);
      break;

   } 
   delay(1);
}
