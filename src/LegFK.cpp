#include "LegFK.hpp"

Vector3f LegFK(Vector3f v){
  float j1 = cos(v.y /180 * PI)*femurLength; 
  float z1 = sin(v.y /180 * PI)*femurLength;

  float j2 = cos((v.y + v.z) /180 * PI)*tibiaLength;
  float z2 = sin((v.y + v.z) /180 * PI)*tibiaLength;
  
  float x = cos(v.x /180 * PI)*(j1 + j2 + coxaLength);
  float y = sin(v.x /180 * PI)*(j1 + j2 + coxaLength);
  float z = z1 + z2;
  Vector3f result(x,y,z);
  return result;
  }
