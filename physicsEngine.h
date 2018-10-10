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
    void set_gravity(double xAccel, double yAccel, double zAccel);
    void add_sphere();
    void update(double s);
    dynVector get_gravity_vec();
};


#endif
