#include "Body.hpp"

void Body::positionAt(Vector3f p){
  Vector3f legHomePosition_coordinates = LegFK(legHomePosition); 
  Vector3f temp;
  Vector3f newPositions[6];
  float z = -p.z + legHomePosition_coordinates.z;
  for(int i = 0; i < 6; i++){
    newPositions[i].z = z;
  }
  newPositions[0].x = cos(bodyAngle_rad) * (-p.x) - sin(bodyAngle_rad) * (-p.y) + legHomePosition_coordinates.x; //from body coordinate system to leg coordinate system  
  newPositions[0].y = sin(bodyAngle_rad) * (p.x) + cos(bodyAngle_rad) * (-p.y) + legHomePosition_coordinates.y;


  newPositions[1].x = cos(-bodyAngle_rad) * (p.x) - sin(-bodyAngle_rad) * (p.y) + legHomePosition_coordinates.x;
  newPositions[1].y = sin(-bodyAngle_rad) * (p.x) + cos(-bodyAngle_rad) * (p.y) + legHomePosition_coordinates.y;
  
  newPositions[2].x = -p.x + legHomePosition_coordinates.x;
  newPositions[2].y = -p.y + legHomePosition_coordinates.y;

  newPositions[3].x = p.x + legHomePosition_coordinates.x; 
  newPositions[3].y = p.y + legHomePosition_coordinates.y;

  newPositions[4].x = cos(-bodyAngle_rad) * (-p.x) - sin(-bodyAngle_rad) * (-p.y) + legHomePosition_coordinates.x; 
  newPositions[4].y = sin(-bodyAngle_rad) * (-p.x) + cos(-bodyAngle_rad) * (-p.y) + legHomePosition_coordinates.y;

  newPositions[5].x = cos(bodyAngle_rad) * (p.x) - sin(bodyAngle_rad) * (p.y) + legHomePosition_coordinates.x;
  newPositions[5].y = sin(bodyAngle_rad) * (p.x) + cos(bodyAngle_rad) * (p.y) + legHomePosition_coordinates.y; 

  for(float t = 0; t <= 1; t += 1){
    temp = lerp(prevPositions[0], newPositions[0], t);
    legs[0].positionAt(temp);
    temp = lerp(prevPositions[1], newPositions[1], t);
    legs[1].positionAt(temp);
    temp = lerp(prevPositions[2], newPositions[2], t);
    legs[2].positionAt(temp);
    temp = lerp(prevPositions[3], newPositions[3], t);
    legs[3].positionAt(temp);
    temp = lerp(prevPositions[4], newPositions[4], t);
    legs[4].positionAt(temp);
    temp = lerp(prevPositions[5], newPositions[5], t);
    legs[5].positionAt(temp);
  }
  for(int i = 0; i < 6; i++){
    prevPositions[i] = newPositions[i];
  }
  position = p;
}