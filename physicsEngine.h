// Author: Benjamin Hilton
// Date: October 2018



#include "dynVector.h"

#ifndef PHYSICSENGINE_H_
#define PHYSICSENGINE_H_

class PhysicsEngine
{
public:
    PhysicsEngine() :
        gravityVec{0, 0, -9.8},
        velocityVec{0, 0, 0},
        displaceVec{0,0,0} {}
    ~PhysicsEngine(){}
    dynVector gravityVec;
    dynVector velocityVec;
    dynVector displaceVec;
    void setGravity(double x_accel, double y_accel, double z_accel);
    void setVelocity(double x_dot, double y_dot, double z_dot);
    void setDisplace(double X, double Y, double Z);
    void update(double s);
};

#endif
