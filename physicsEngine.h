// Author: Benjamin Hilton
// Date: October 2018


#ifndef PHYSICSENGINE_H_
#define PHYSICSENGINE_H_


#include "dynVector.h"
#include "object3d.h"
#include <vector>


class PhysicsEngine  
{
public:
    PhysicsEngine() :
        gravityVec{0, 0, -9.8}{}
    ~PhysicsEngine(){}
    dynVector gravityVec;
    std::vector<Object3D> ObjList;
    void setGravity(double x_accel, double y_accel, double z_accel);
    void addSphere();
    void update(double s);
    dynVector getGravityVec();
};


#endif
