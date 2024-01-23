#ifndef TRIANGULARPATH 
#define TRIANGULARPATH
#include "Vector3f.hpp"
#include "lerp.hpp"
#include "bezier_2.hpp"
#include "LegFK.hpp"
#include <math.h>
#define PI 3.1415926535897932384626433832795

class TriangularPath {
public:
    float strideLength; // distance covered in one walk cycle.
    float triangleWidth;
    float height;
    float d; 
    Vector3f home;
    Vector3f Point_B;
    Vector3f Point_A; 
    float angle_rad;        // angle_rad of triangle_rad BEI
    Vector3f Point_C;
    Vector3f Point_E;
    Vector3f Point_D;
    Vector3f Point_F;
    Vector3f Point_H;
    Vector3f Point_G;
    Vector3f Point_I; 
    TriangularPath(){}
    TriangularPath(float StrideLength, float TriangleWidth, float Height)
        : strideLength(StrideLength), triangleWidth(TriangleWidth), height(Height), 
          home(LegFK(legHomePosition)),
          d((triangleWidth - strideLength)/2),
          Point_B(home.x, -triangleWidth/2, home.z),
          Point_A(home.x, -strideLength/2, Point_B.z),
          angle_rad(atan(height / (d + strideLength/2))),
          Point_C(home.x, Point_B.y + cos(angle_rad) * d, Point_B.z + sin(angle_rad) * d),
          Point_E(home.x, 0, height + home.z),
          Point_D(home.x, Point_E.y - cos(angle_rad) * d, Point_E.z - sin(angle_rad) * d),
          Point_F(home.x, Point_E.y + cos(angle_rad) * d, Point_E.z -sin(angle_rad) * d),
          Point_H(home.x, triangleWidth/2, home.z),
          Point_G(home.x, Point_H.y - cos(angle_rad) * d, Point_H.z + sin(angle_rad) * d),
          Point_I(home.x, Point_H.y - d , Point_H.z) {}

    Vector3f trace(float t);
};
#endif
