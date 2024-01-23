#ifndef VECTOR3F_H
#define VECTOR3F_H
#include "Arduino.h"
class Vector3f{
  public: 
  float x,y,z;
  Vector3f(): x(0.0f), y(0.0f), z(0.0f){}

  Vector3f(float X, float Y, float Z): x(X), y(Y), z(Z){}

  Vector3f(const Vector3f& v): x(v.x), y(v.y), z(v.z){}

  static Vector3f add(Vector3f v, float X, float Y, float Z){
    return Vector3f(v.x+X, v.y+Y, v.z+Z);
  }
  static Vector3f add(Vector3f a, Vector3f b){
    return Vector3f(a.x+b.x, a.y+b.y, a.z+b.z);
  }
  void add(float X, float Y, float Z){
    x+=X;
    y+=Y;
    z+=Z;
  }
  void add(Vector3f v){
    x+=v.x;
    y+=v.y;
    z+=v.z;
  }

  void subtract(Vector3f v){
    x-=v.x;
    y-=v.y;
    z-=v.z;
  }
  void scale(float k){
    x*=k;
    y*=k;
    z*=k;
  }
  void multiplyBy(Vector3f v){
    x*= v.x;
    y*= v.y;
    z*= v.z;
  }
  void print(){
    Serial.print("("); Serial.print(x); Serial.print(" / "); Serial.print(y); Serial.print(" / "); Serial.print(z); Serial.println(")");
  }
};
#endif