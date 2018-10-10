// Author: Benjamin Hilton
// Date: October 2018

#include "physicsEngine.h"
#include "object3d.h"
#include <vector>


void PhysicsEngine::set_gravity(double xAccel, double yAccel, double zAccel)
{
    gravityVec.xValue = xAccel;
    gravityVec.yValue = yAccel;
    gravityVec.zValue = zAccel;
}

dynVector PhysicsEngine::get_gravity_vec()
{
    return gravityVec;
}

void PhysicsEngine::add_sphere()
{
    Object3D object;
    object.accelVec = gravityVec;
    ObjList.push_back(object);
}
void PhysicsEngine::update(double s)
{
    for (unsigned int i = 0; i < ObjList.size(); i++)
    {
        ObjList[i].update(s);
    }
}
