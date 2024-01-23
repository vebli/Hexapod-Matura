#include "Leg.hpp"

void Leg::positionAt(Vector3f p){
  float j1, j2, j3;
  float alpha, beta, gamma; 
  float j =  sqrt(pow(p.x, 2) + pow(p.y,2));
  float L = sqrt(pow(j-coxaLength, 2) + pow(p.z,2));
  
  if(L>= femurLength+tibiaLength){
    Serial.print("Error: Leg "); Serial.print(legID); Serial.println(" coordinates out of reach."); 
  }
  else{
    j1 = (p.x != 0) ? atan(p.y/p.x) / PI * 180 : 0;
    gamma = acos((pow(femurLength,2) + pow(tibiaLength,2) - pow(L,2))/(2*femurLength*tibiaLength))/ PI * 180; //cos theorem
    j3 = gamma - 180;
    alpha = atan(p.z/(j-coxaLength));
    beta = acos(((pow(L,2) + pow(femurLength,2) - pow(tibiaLength,2))/(2*L*femurLength)));
    j2 = (alpha + beta) / PI * 180;
    if(-90 <= j1 && j1 <= 90 && -135 <= j2 && j2 <= 135 && -135 - tibiaAngle <= j3 && j3 <= 135 - tibiaAngle){
      prevJointAngles.x = jointAngles.x;
      prevJointAngles.y = jointAngles.y;
      prevJointAngles.z = jointAngles.z;
      jointAngles.x = j1;
      jointAngles.y = j2;
      jointAngles.z = j3; 
      update();
    }
    else{
      Serial.print("Error: Leg "); Serial.print(legID); Serial.print(" Trying to rotate further than Servo allows: "); 
      Serial.print(j1); Serial.print(" "); Serial.print(j2); Serial.print(" "); Serial.println(j3); 
    } 
  }
}

void Leg::positionAt(Vector3f p, float velocity){
  float j1, j2, j3;
  float alpha, beta, gamma; 
  float j =  sqrt(pow(p.x, 2) + pow(p.y,2));
  float L = sqrt(pow(j-coxaLength, 2) + pow(p.z,2));
  
  if(L>= (femurLength+tibiaLength+coxaLength)){
    Serial.print("Error: Leg "); Serial.print(legID); Serial.println(" coordinates out of reach."); 
  }
  else{
    j1 = (p.x != 0) ? atan(p.y/p.x) / PI * 180 : 0;
    gamma = acos((pow(femurLength,2) + pow(tibiaLength,2) - pow(L,2))/(2*femurLength*tibiaLength))/ PI * 180; //cos theorem
    j3 = gamma - 180;
    alpha = atan(p.z/(j-coxaLength));
    beta = acos(((pow(L,2) + pow(femurLength,2) - pow(tibiaLength,2))/(2*L*femurLength)));
    j2 = (alpha + beta) / PI * 180;
    if(-90 <= j1 && j1 <= 90 && -135 <= j2 && j2 <= 135 && -135 - tibiaAngle <= j3 && j3 <= 135 - tibiaAngle)
    {
      prevJointAngles.x = jointAngles.x;
      prevJointAngles.y = jointAngles.y;
      prevJointAngles.z = jointAngles.z;
      jointAngles.x = j1;
      jointAngles.y = j2;
      jointAngles.z = j3; 
      update(velocity);
    }
    else{
      Serial.print("Error: Leg "); Serial.print(legID); Serial.print(" Trying to rotate further than Servo allows: "); 
      Serial.print(j1); Serial.print(" "); Serial.print(j2); Serial.print(" "); Serial.println(j3); 
    } 
  }
}