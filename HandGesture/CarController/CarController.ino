#include <Servo.h>
#include <MyoController.h>
#include <SoftwareSerial.h>

#define RxD 2
#define TxD 3

#define WAVE_PIN 9
#define FINGERSSPREAD_PIN 11


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

 pinMode(RxD, INPUT);
pinMode(TxD, OUTPUT);

  pinMode(WAVE_PIN, OUTPUT);
  pinMode(FINGERSSPREAD_PIN, OUTPUT);

  Serial.begin(9600);
  myo.initMyo();
  
}

void loop(){
 
   myo.updatePose();
   switch ( myo.getCurrentPose() ) {
    case rest:
      analogWrite(FINGERSSPREAD_PIN,0); 
      digitalWrite(WAVE_PIN,LOW);
      digitalWrite(FINGERSSPREAD_PIN,LOW);
      break;

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
   /* case doubletap:
    //LED Lights
   
    break;
    case fist:
    //LED Lights
     
      break;*/

   } 
   delay(1);
}
