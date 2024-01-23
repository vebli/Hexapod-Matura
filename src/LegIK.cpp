#include "LegIK.hpp"


Vector3f LegIK(Vector3f p){
  float j =  sqrt(pow(p.x, 2) + pow(p.y,2));
  float L = sqrt(pow(j-coxaLength, 2) + pow(p.z,2));
  
  if(L >= femurLength + tibiaLength){
    Serial.println("Error: Coordinate out of reach");
  }
  else{
    Vector3f angles;
    angles.x = (p.x != 0) ? atan(p.y/p.x) / PI * 180: 0;
    float gamma = acos((pow(femurLength,2) + pow(tibiaLength,2) - pow(L,2))/(2*femurLength*tibiaLength))/ PI * 180;
    angles.z = gamma - 180;
    float alpha = atan(p.z/(j-coxaLength));
    float beta = acos(((pow(L,2) + pow(femurLength,2) - pow(tibiaLength,2))/(2*L*femurLength)));
    angles.y = (alpha + beta) / PI * 180;
    return(angles);
  }

}