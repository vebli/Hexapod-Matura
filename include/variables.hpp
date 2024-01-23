#ifndef VARIABLES_H
#define VARIABLES_H
#include <Adafruit_PWMServoDriver.h>
#include "Vector3f.hpp"

//distances in cm, angles in degrees
//Leg
const float coxaLength = 6.314;
const float femurLength = 9;
const float tibiaLength = 15.6056;
const int tibiaAngle = 20;
const Vector3f legHomePosition(0,30,-90);
 //Body
const float bodyAngle = 60;
const float bodyAngle_rad = 60.f / 180.f * PI;
const float closeCoxaOffsetX = 11.137;
const float farCoxaOffsetX = 7.196;
const float farCoxaOffsetY = 12.4638;
const float farCoxaDistance = sqrt(pow(farCoxaOffsetX,2) + pow(farCoxaOffsetY,2));
const float zOffset = 0;
//Matrix
enum class rotation{roll, pitch, jaw};
//SERVO VALUES
const int SERVOMIN= 204.8;
const int SERVOMAX = 1024; 
const int SERVOMAX_DEG = 270;
const int freq = 100;
const int SERVOREST = 614.4;
const float angleOffset = 135;
//GAIT
const float legVelocity = 100;//cm/s
const float stepsPerUpdate = 3;
const float stepsPerWalkUpate = 50;
const float strideLength = 6;

extern Adafruit_PWMServoDriver pwmCtrlR;
extern Adafruit_PWMServoDriver pwmCtrlL;
#endif // VARIABLES_H

