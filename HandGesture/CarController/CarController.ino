#include <Servo.h>
#include <MyoController.h>


#define WAVEIN_PIN 9
#define WAVEOUT_PIN 9
#define FINGERSSPREAD_PIN 11
#define DOUBLETAP_PIN 11

MyoController myo = MyoController();
Servo serv;
Servo servo1;

void setup() {
  serv.attach(11);
  servo1.attach(9);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);


  pinMode(WAVEIN_PIN, OUTPUT);
  pinMode(WAVEOUT_PIN, OUTPUT);
  pinMode(FINGERSSPREAD_PIN, OUTPUT);
  pinMode(DOUBLETAP_PIN, OUTPUT);
  Serial.begin(9600);
  myo.initMyo();
  digitalWrite(3,HIGH);
  delay(300);
  digitalWrite(3,LOW);
  delay (150);
  digitalWrite(3,HIGH);
  delay(300);
  digitalWrite(3,LOW);
  delay (300);
  digitalWrite(3,HIGH);
  delay(1500);
  digitalWrite(3,LOW);
  
}

void loop(){
   myo.updatePose();
   switch ( myo.getCurrentPose() ) {
    case rest:

      digitalWrite(9,LOW);
      break;

    case waveIn:
      digitalWrite(WAVEIN_PIN,HIGH);
      digitalWrite(9, HIGH);
      servo1.write(0);
      break;
    case waveOut:
      digitalWrite(WAVEOUT_PIN,HIGH);
      digitalWrite(9, HIGH);
      servo1.write(180);
      break;
    case fingersSpread:
     digitalWrite(FINGERSSPREAD_PIN,HIGH);
      break;
//    case doubleTap:
//       digitalWrite(DOUBLETAP_PIN,LOW);
//      break;
   } 
   delay(1);
}
