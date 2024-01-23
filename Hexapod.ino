#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
#include "Vector3f.hpp"
#include "variables.hpp"
#include "Leg.hpp"
#include "Body.hpp"
#include "LegIK.hpp"
#include "LegFK.hpp"
Adafruit_PWMServoDriver pwmCtrlR = Adafruit_PWMServoDriver(0x40);
Adafruit_PWMServoDriver pwmCtrlL = Adafruit_PWMServoDriver(0x41);
Leg leg1(1);
Leg leg2(2);
Leg leg3(3);
Leg leg4(4);
Leg leg5(5);
Leg leg6(6);

Body body;
float t;
float mode;
Vector3f bodyPosition;
int walkMode = 0 ;
int positionMode = 1;
bool modeSelected;
enum class controls{
  STOP = 48,
  FORWARD = 49, 
  RIGHT = 50, 
  BACKWARD = 51, 
  LEFT = 52, 
  BODYIK = 53
};

void setup() {
  Wire.begin();
  Serial.begin(9600);
  pwmCtrlR.begin();
  pwmCtrlR.reset();
  pwmCtrlR.setPWMFreq(freq);
  pwmCtrlL.begin();
  pwmCtrlL.reset();
  pwmCtrlL.setPWMFreq(freq);
  pinMode(12,OUTPUT);
  digitalWrite(12, HIGH);
}

void loop() {
  //Serial.print("Bluetooth value: "); Serial.println(walkMode); 
  delay(1000);
  Serial.println("Choose Mode: "); Serial.println("1 - walk"); Serial.println("2 - position");
  if(Serial.available() > 0){
    mode = Serial.parseInt();
  }
  if(mode == 1){
    while(true){
      if (Serial.available()){
        walkMode = Serial.parseInt();
      }
      if(t > 1){
        t -= static_cast<int>(t);
      }
      else if(t < 0){
        int truncated = static_cast<int>(t);
        t += (truncated + 1);
      }
      if(walkMode == 1){
        Serial.println("Walking Forwards");
        body.walk(t);
        t += 0.05;
      }
      else if(walkMode == 2){
        Serial.println("Walking Backwards");
        body.walk(t);
        t -= 0.05;
      }
      else if(walkMode == 3){
        Serial.println("Exiting Walk Mode");
        break;
      }
      else{
        Serial.println("Chose Walk Mode"); Serial.println("1 - Forwards"); Serial.println("2 - Backwards"); Serial.println("3 - Exit");
        delay(1000);
      }
    }
  }
  if(mode == 2){
    float x,y, radius = 2.5;
    Vector3f position;
    while(true){
      if(Serial.available()){
        positionMode = Serial.parseInt();
      }
      if(positionMode == 1){
        Serial.println("Circling");
        for (int i = 0; i < 360; i+= 6){
        float a = i * 2 * PI / 360;
          position.x = cos(a) * radius;
          position.y = sin(a) * radius;
          //body.positionAt(Vector3f(x,y,0));
          body.positionAt(position);
        }
      }
      else if(positionMode == 2){
        Serial.println("Exiting Position Mode");
        break;
      }
      else{
        Serial.println("Chose Position Mode"); Serial.println("1 - Circle CCW"); Serial.println("2 - Exit");
        delay(1000);
      }
    }
  }
}