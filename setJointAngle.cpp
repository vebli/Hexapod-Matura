#include "Leg.hpp" 
void Leg::setJointAngle(int J, float deg)
{
  if(J == 1)
  {
    prevJointAngles.x = jointAngles.x;
    jointAngles.x = deg;
    update();
  }
  else if(J == 2)
  {
    prevJointAngles.y = jointAngles.y;
    jointAngles.y = deg;
    update();
  }
  else if (J == 3)
  {
    prevJointAngles.z = jointAngles.z;
    jointAngles.z = deg; 
    update();
  }
  else
  {
    Serial.println("Error: Joints are numbered from 1-3");
  }
}
