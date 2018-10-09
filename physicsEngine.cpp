// Author: Benjamin Hilton
// Date: October 2018

#include "physicsEngine.h"
#include "object3d.h"
#include <vector>


void PhysicsEngine::setGravity(double x_accel, double y_accel, double z_accel)
{
    gravityVec.x_value = x_accel;
    gravityVec.y_value = y_accel;
    gravityVec.z_value = z_accel;
}

dynVector PhysicsEngine::getGravityVec()
{
    return gravityVec;
}

void PhysicsEngine::addSphere()
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
