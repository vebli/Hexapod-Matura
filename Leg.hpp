#ifndef LEG_H
#define LEG_H
#include "Arduino.h"
#include "Vector3f.hpp"
#include "variables.hpp"
#include "dtopw.hpp"
#include "LegFK.hpp"

class Leg{
  private:
  const int legID; // left side odd number, right side even numbers. Starting at front left beginning with 1

  public:
  Vector3f jointAngles; // Joint Angles from -135 to + 135
  Vector3f prevJointAngles;
  
  Leg(int id): legID(id){}
  
  void setJointAngle(int J, float deg);
  void positionAt(Vector3f p);
  void positionAt(Vector3f p, float velocity);
  void rotate(float roll, float pitch, float jaw);
  void update();
  void update(float velocity);
};

#endif