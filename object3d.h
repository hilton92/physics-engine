//Author: Benjamin Hilton

#ifndef OBJECT3D_H_
#define OBJECT3D_H_

#include "dynVector.h"

class Object3D
{
public:
    Object3D() :
        accelVec{0,0,0},
        velocityVec{0,0,0},
        displaceVec{0,0,0} {}
    ~Object3D(){}
    dynVector accelVec;
    dynVector velocityVec;
    dynVector displaceVec;
    double radius;
    double coefOfRest = 0.8;
    void set_velocity(double xDot, double yDot, double zDot);
    void set_displace(double X, double Y, double Z);
    void set_accel(double xAccel, double yAccel, double zAccel);
    void update(double s);
    void collision_detect();
};

#endif
