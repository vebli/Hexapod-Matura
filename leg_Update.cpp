#include "Leg.hpp"
void Leg::update(){
  int servoIndex = 0;
  float timeIterator = 1/stepsPerUpdate;
  Vector3f location(LegFK(jointAngles));
  Vector3f prevLocation(LegFK(prevJointAngles));
  float travelDistance = sqrt(pow(location.x - prevLocation.x, 2) + pow(location.y - prevLocation.y, 2) + pow(location.z - prevLocation.z, 2));
  float travelTime = (travelDistance / legVelocity) * 1000; // s -> ms
  float delayPerIteration = travelTime / stepsPerUpdate;
  // Serial.print("distance: "); Serial.print(travelDistance);
  // Serial.print("\t Travel Time:"); Serial.print(travelTime);
  // Serial.print("\tSteps: "); Serial.print(stepsPerUpdate);
  // Serial.print("\tdelay Per Step: "); Serial.println(delayPerIteration);

  if(legID % 2 == 1)  // Odd legIDs (left side)
  {
    servoIndex = ((legID+1)/2 -1)*4;
    
    for(float t = 0; t <= 1; t += timeIterator){
      pwmCtrlL.setPWM(servoIndex, 0 , dtopw(prevJointAngles.x + (jointAngles.x-prevJointAngles.x)*t));
      pwmCtrlL.setPWM(servoIndex + 1, 0, dtopw(-(prevJointAngles.y + (jointAngles.y- prevJointAngles.y)*t)));
      pwmCtrlL.setPWM(servoIndex + 2, 0, dtopw(prevJointAngles.z + (jointAngles.z-prevJointAngles.z)*t + tibiaAngle));   
      delay(delayPerIteration);
    }
  }

  else if(legID % 2 == 0) // Even LegIDs (right side)
  {
    servoIndex = (legID/2 -1)*4;
    for(float t = 0; t <= 1; t += timeIterator){
      pwmCtrlR.setPWM(servoIndex, 0, dtopw(prevJointAngles.x + (jointAngles.x-prevJointAngles.x)*t));
      pwmCtrlR.setPWM(servoIndex + 1, 0, dtopw(prevJointAngles.y + (jointAngles.y- prevJointAngles.y)*t));
      pwmCtrlR.setPWM(servoIndex + 2, 0, dtopw(-(prevJointAngles.z + (jointAngles.z-prevJointAngles.z)*t + tibiaAngle)));
      delay(delayPerIteration);
    }
  }
}

void Leg::update(float velocity){
  int servoIndex = 0;
  float timeIterator = 1/stepsPerUpdate;
  float delayPerIteration;
  if(velocity != 0){ 
    Vector3f location(LegFK(jointAngles));
    Vector3f prevLocation(LegFK(prevJointAngles));
    float travelDistance = sqrt(pow(location.x - prevLocation.x, 2) + pow(location.y - prevLocation.y, 2) + pow(location.z - prevLocation.z, 2));
    float travelTime = (travelDistance / velocity) * 1000; // s -> ms
    delayPerIteration = travelTime / stepsPerUpdate;
  }
  else{
    delayPerIteration = 0;
  }
  if(legID % 2 == 1)  // Odd legIDs (left side)
  {
    servoIndex = ((legID+1)/2 -1)*4;
    for(float t = 0; t <= 1; t += timeIterator){
      pwmCtrlL.setPWM(servoIndex, 0 , dtopw(prevJointAngles.x + (jointAngles.x-prevJointAngles.x)*t));
      pwmCtrlL.setPWM(servoIndex + 1, 0, dtopw(-(prevJointAngles.y + (jointAngles.y- prevJointAngles.y)*t)));
      pwmCtrlL.setPWM(servoIndex + 2, 0, dtopw(prevJointAngles.z + (jointAngles.z-prevJointAngles.z)*t + tibiaAngle));   
      delay(delayPerIteration);
    }
  }
  else if(legID % 2 == 0) // Even LegIDs (right side)
  {
    servoIndex = (legID/2 -1)*4;
    for(float t = 0; t <= 1; t += timeIterator){
      pwmCtrlR.setPWM(servoIndex, 0, dtopw(prevJointAngles.x + (jointAngles.x-prevJointAngles.x)*t));
      pwmCtrlR.setPWM(servoIndex + 1, 0, dtopw(prevJointAngles.y + (jointAngles.y- prevJointAngles.y)*t));
      pwmCtrlR.setPWM(servoIndex + 2, 0, dtopw(-(prevJointAngles.z + (jointAngles.z-prevJointAngles.z)*t + tibiaAngle)));
      delay(delayPerIteration);
    }
  }
}