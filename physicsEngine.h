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
        gravityVec{0, 0, -9.8}, fluidDensity{1.275}{}
    ~PhysicsEngine(){}
    dynVector gravityVec;
    double fluidDensity;
    std::vector<Object3D> ObjList;
    void set_gravity(double xAccel, double yAccel, double zAccel);
    void set_fluid_density(double density);
    void add_sphere(double radius, double mass, double coefficientOfRestitution, double xPos, double yPos, double zPos, double xVel, double yVel, double zVel);
    void update(double s);
    void set_new_gravity();
    void set_new_fluid_density();
    dynVector get_gravity_vec();
    void clear();
    void collision_check(unsigned int index);
    bool determine_if_collision_occurred(unsigned int sphereIndex1, unsigned int sphereIndex2);
    void collision_occurred(unsigned int sphereIndex1, unsigned int sphereIndex2);
    void move_to_avoid_intersection(unsigned int sphereIndex1, unsigned int sphereIndex2);
};

#endif
