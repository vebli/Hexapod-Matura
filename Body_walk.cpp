#include "Body.hpp"

void Body::walk(float t){
  Vector3f tempVector;
  Vector3f rotatedVector1;
  Vector3f rotatedVector2;
  const float x_offset = 8;
  const float y_offset = 10;
  const float phaseShift = 0.5; 
  const float a = cos(bodyAngle_rad), b = -sin(bodyAngle_rad);
  const float c = sin(bodyAngle_rad), d = cos(bodyAngle_rad); 
  float home = 0.5/6.f; //So trace doesent starts at home instead of point I.
  tempVector = walkCycle.trace(home+1-t + phaseShift);
  //LEG 1
  rotatedVector1.x = a*tempVector.x + b*tempVector.y;
  rotatedVector1.y = c*tempVector.x + d*tempVector.y;
  rotatedVector1.z = tempVector.z;
  rotatedVector1.add(x_offset, -y_offset, 0);
  legs[0].positionAt(rotatedVector1);
  //LEG 2
  tempVector = walkCycle.trace(home+t);
  rotatedVector2.x = a*tempVector.x - b*tempVector.y;
  rotatedVector2.y = -c*tempVector.x + d*tempVector.y;
  rotatedVector2.z = tempVector.z;
  rotatedVector2.add(x_offset, y_offset, 0);
  legs[1].positionAt(rotatedVector2);
  //LEG 3
  legs[2].positionAt(walkCycle.trace(home-t));
  //LEG 4
  legs[3].positionAt(walkCycle.trace(home+t + phaseShift));
  //LEG 5
  tempVector = walkCycle.trace(home+phaseShift-t);
  rotatedVector2.x = a*tempVector.x - b*tempVector.y;
  rotatedVector2.y = -c*tempVector.x + d*tempVector.y;
  rotatedVector2.z = tempVector.z;
  rotatedVector2.add(x_offset, y_offset, 0);
  legs[4].positionAt(rotatedVector2);
  //LEG 6
  tempVector = walkCycle.trace(home+t);
  rotatedVector1.x = a*tempVector.x + b*tempVector.y;
  rotatedVector1.y = c*tempVector.x + d*tempVector.y;
  rotatedVector1.z = tempVector.z;
  rotatedVector1.add(x_offset,-y_offset, 0);
  legs[5].positionAt(rotatedVector1);

}

void Body::walk(float t, float velocity){
  Vector3f tempVector;
  Vector3f rotatedVector1;
  Vector3f rotatedVector2;
  const float x_offset = 8;
  const float y_offset = 10;
  const float phaseShift = 0.5; 
  const float a = cos(bodyAngle_rad), b = -sin(bodyAngle_rad);
  const float c = sin(bodyAngle_rad), d = cos(bodyAngle_rad); 
  float home = 0.5/6.f; //So trace doesent starts at home instead of point I.
  tempVector = walkCycle.trace(home+1-t + phaseShift);
  //LEG 1
  rotatedVector1.x = a*tempVector.x + b*tempVector.y;
  rotatedVector1.y = c*tempVector.x + d*tempVector.y;
  rotatedVector1.z = tempVector.z;
  rotatedVector1.add(x_offset, -y_offset, 0);
  legs[0].positionAt(rotatedVector1, velocity);
  //LEG 2
  tempVector = walkCycle.trace(home+t);
  rotatedVector2.x = a*tempVector.x - b*tempVector.y;
  rotatedVector2.y = -c*tempVector.x + d*tempVector.y;
  rotatedVector2.z = tempVector.z;
  rotatedVector2.add(x_offset, y_offset, 0);
  legs[1].positionAt(rotatedVector2, velocity);
  //LEG 3
  legs[2].positionAt(walkCycle.trace(home-t), velocity);
  //LEG 4
  legs[3].positionAt(walkCycle.trace(home+t + phaseShift), velocity);
  //LEG 5
  tempVector = walkCycle.trace(home+phaseShift-t);
  rotatedVector2.x = a*tempVector.x - b*tempVector.y;
  rotatedVector2.y = -c*tempVector.x + d*tempVector.y;
  rotatedVector2.z = tempVector.z;
  rotatedVector2.add(x_offset, y_offset, 0);
  legs[4].positionAt(rotatedVector2, velocity);
  //LEG 6
  tempVector = walkCycle.trace(home+t);
  rotatedVector1.x = a*tempVector.x + b*tempVector.y;
  rotatedVector1.y = c*tempVector.x + d*tempVector.y;
  rotatedVector1.z = tempVector.z;
  rotatedVector1.add(x_offset,-y_offset, 0);
  legs[5].positionAt(rotatedVector1, velocity);

}
