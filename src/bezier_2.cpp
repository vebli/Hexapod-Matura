#include "bezier_2.hpp"

Vector3f bezier_2(Vector3f A, Vector3f B, Vector3f C, float t){
  Vector3f result = lerp(lerp(A, B, t), lerp(B, C, t), t);
  return(result);
}