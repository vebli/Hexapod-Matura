#include "lerp.hpp"

Vector3f lerp(Vector3f A, Vector3f B, float t){
  Vector3f result;
  result.x  = (1-t)*A.x + B.x*t;
  result.y  = (1-t)*A.y + B.y*t;
  result.z  = (1-t)*A.z + B.z*t;
  return(result);
}