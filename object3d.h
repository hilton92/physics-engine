//Author: Benjamin Hilton

#ifndef OBJECT3D_H_
#define OBJECT3D_H_

#include "dynVector.h"
#include <cmath>

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
    void setVelocity(double x_dot, double y_dot, double z_dot);
    void setDisplace(double X, double Y, double Z);
    void setAccel(double x_accel, double y_accel, double z_accel);
    void update(double s);
    void collisionDetect();
};

#endif
