#ifndef BODY_H
#define BODY_H
#include "Leg.hpp"
#include "Vector3f.hpp"
#include "LegFK.hpp"
#include "LegIK.hpp"
#include "TriangularPath.hpp"
class Body{
  private:
  Vector3f position;
  Vector3f prevPositions[6];
  public:
  Leg legs[6] = {Leg(1), Leg(2), Leg(3), Leg(4), Leg(5), Leg(6)};
  TriangularPath walkCycle;
  Body() : position(Vector3f(0,0,0)), walkCycle(strideLength, strideLength + 6, 10){
    for(int i = 0; i < 6 ; i++){
      prevPositions[i] = LegFK(legHomePosition);
    }
  }
  void positionAt(Vector3f p);
  void walk(float t);
  void walk(float t, float velocity);
};
#endif 