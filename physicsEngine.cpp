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

void PhysicsEngine::set_fluid_density(double density)
{
    fluidDensity = density;
}

dynVector PhysicsEngine::get_gravity_vec()
{
    return gravityVec;
}

void PhysicsEngine::add_sphere(double radius, double mass, double coefficientOfRestitution, double xPos, double yPos, double zPos, double xVel, double yVel, double zVel)
{
    Object3D object;
    object.accelVec = gravityVec;
    object.fluidDensity = fluidDensity;
    object.set_displace(xPos, yPos, zPos);
    object.set_velocity(xVel, yVel, zVel);
    object.set_radius(radius);
    object.set_mass(mass);
    object.set_coefficient_of_restitution(coefficientOfRestitution);
    ObjList.push_back(object);
}
void PhysicsEngine::update(double s)
{
    for (unsigned int i = 0; i < ObjList.size(); i++)
    {
        ObjList[i].update(s);
    }
}
