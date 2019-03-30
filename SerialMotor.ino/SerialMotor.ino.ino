#include <SoftwareSerial.h>

#define txPin 3
#define rxPin 4
SoftwareSerial BLE(rxPin, txPin);// rx tx
int counter=0;
unsigned long crazyLong = 0;


void setup() {
  // put your setup code here, to run once:
BLE.begin(9600);
//
pinMode(13, OUTPUT);
//
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  while(BLE.available()){
    char c = BLE.read();
    BLE.print(c);
  
    c = Serial.read();
   
   if (c == 1) {
    digitalWrite(13, HIGH);
    }
  
    /*if( == 0)
      digitalWrite (13, LOW);*/
  }
  BLE.println(counter);
  counter++;
  delay(1000);
}
