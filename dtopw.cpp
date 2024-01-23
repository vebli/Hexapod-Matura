#include "dtopw.hpp"

float dtopw(float deg) //-135 to +135
{
  float result = (SERVOMAX-SERVOMIN)/270*deg+SERVOREST;
  //float result = (SERVOMAX-SERVOMIN)/270*(deg + angleOffset) + SERVOMIN; //alternative formula
  if(result >= SERVOMIN && result <= SERVOMAX){
    return result;
  }
  else{
    Serial.println("Error: Pulse width out of range"); 
  }
}