#include "TriangularPath.hpp"

Vector3f TriangularPath::trace(float t) 
{
  
  if(t > 1){
    t -= static_cast<int>(t);
  }
  else if(t < 0){
    int truncated = static_cast<int>(t);
    t += (truncated + 1);
  }
  float i = t*6 ;
  if(i >= 0 && i <= 1){
    return(lerp(Point_I, Point_A, t*6));
  }
  else if(i > 1  && i <= 2){
    return(bezier_2(Point_A, Point_B, Point_C, t*6-1));
  }

  else if(i > 2  && i <= 3){
    return(lerp(Point_C, Point_D, t*6-2));
  }

  else if(i > 3  && i <= 4){
    return(bezier_2(Point_D, Point_E, Point_F, t*6-3));
  }

  else if(i > 4  && i <= 5){
    return(lerp(Point_F, Point_G, t*6-4));
  }

  else if(i > 5  && i <= 6){
    return(bezier_2(Point_G, Point_H, Point_I, t*6-5));
  }
  
  else
  {
    Serial.println("TraingularPath::Trace only takes values between 0 - 1");
  }
}

