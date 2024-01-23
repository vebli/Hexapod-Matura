#include "Leg.hpp"

void Leg::rotate(float roll, float pitch, float yaw){
  Vector3f currentLegPosition = LegFK(jointAngles);
  Vector3f B_currentLegPosition;
  B_currentLegPosition.x = cos(bodyAngle_rad)*(currentLegPosition.x) - sin(bodyAngle_rad)*(currentLegPosition.y) + farCoxaOffsetX; 
  B_currentLegPosition.y = sin(bodyAngle_rad)*(currentLegPosition.x) + cos(bodyAngle_rad)*(currentLegPosition.y) + farCoxaOffsetY; 
  B_currentLegPosition.z = currentLegPosition.z;

  float tmp_x = B_currentLegPosition.x;
  float tmp_y = B_currentLegPosition.y;
  float tmp_z = B_currentLegPosition.z;

  //roll 
  float y_roll = tmp_y * cos(roll/180*PI) - tmp_z * sin(roll/180*PI);
  float z_roll = tmp_y * sin(roll/180*PI) + tmp_z * cos(roll/180*PI);

  tmp_y = y_roll;
  tmp_z = z_roll;

  //pitch
  float x_pitch = tmp_x * cos(pitch/180*PI) - tmp_z * sin(pitch/180*PI);
  float z_pitch = tmp_x * sin(pitch/180*PI) + tmp_z * cos(pitch/180*PI);

  tmp_x = x_pitch;
  tmp_z = z_pitch;

  //yaw
  float x_yaw = tmp_x * cos(yaw/180*PI) - tmp_y * sin(yaw/180*PI);
  float y_yaw = tmp_x * sin(yaw/180*PI) + tmp_y * cos(yaw/180*PI);

  tmp_x = cos(-bodyAngle_rad)*(x_yaw - farCoxaOffsetX) - sin(-bodyAngle_rad)*(y_yaw - farCoxaOffsetX) ; 
  tmp_y = sin(-bodyAngle_rad)*(x_yaw - farCoxaOffsetY) + cos(-bodyAngle_rad)*(y_yaw - farCoxaOffsetY) ; 
  positionAt(Vector3f(tmp_x, tmp_y, tmp_z));
}