// Author: Benjamin Hilton
// Date: October 2018

#include "physicsEngine.h"
#include "object3d.h"
#include "dynVector.h"
#include <vector>
#include <cmath>


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
    object.gravityVec = gravityVec;
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
        collision_check(i);
    }
}

void PhysicsEngine::set_new_gravity()
{
    for (unsigned int i = 0; i < ObjList.size(); i++)
    {
        ObjList[i].gravityVec = gravityVec;
    }
}

void PhysicsEngine::set_new_fluid_density()
{
    for (unsigned int i = 0; i < ObjList.size(); i++)
    {
        ObjList[i].fluidDensity = fluidDensity;
    }
}

void PhysicsEngine::clear()
{
    ObjList.clear();
}

void PhysicsEngine::collision_check(unsigned int index)
{
    unsigned long int size = ObjList.size();
    for (unsigned int i = 0; i < size; i++)
    {
        if (i != index)
        {
            if (determine_if_collision_occurred(index, i))
            {
                collision_occurred(index, i);
            }
        }
    }
}

bool PhysicsEngine::determine_if_collision_occurred(unsigned int sphereIndex1, unsigned int sphereIndex2)
{
    double radiusSum = ObjList[sphereIndex1].objectRadius + ObjList[sphereIndex2].objectRadius;
    double xDifference = std::abs(ObjList[sphereIndex1].displaceVec.xValue - ObjList[sphereIndex2].displaceVec.xValue);
    if (radiusSum < xDifference) return false;
    double yDifference = std::abs(ObjList[sphereIndex1].displaceVec.yValue - ObjList[sphereIndex2].displaceVec.yValue);
    if (radiusSum < yDifference) return false;
    double zDifference = std::abs(ObjList[sphereIndex1].displaceVec.zValue - ObjList[sphereIndex2].displaceVec.zValue);
    if (radiusSum < zDifference) return false;
    double distance = sqrt((xDifference*xDifference) + (yDifference*yDifference) + (zDifference*zDifference));
    if (radiusSum < distance) return false;
    else return true;
}


bool PhysicsEngine::check_if_proposed_sphere_interferes(double radius, double xPos, double yPos, double zPos, unsigned int sp)
{
    double radiusSum = radius + ObjList[sp].objectRadius;
    double xDifference = std::abs(xPos - ObjList[sp].displaceVec.xValue);
    if (radiusSum < xDifference) return false;
    double yDifference = std::abs(yPos - ObjList[sp].displaceVec.yValue);
    if (radiusSum < yDifference) return false;
    double zDifference = std::abs(zPos - ObjList[sp].displaceVec.zValue);
    if (radiusSum < zDifference) return false;
    double distance = sqrt((xDifference*xDifference) + (yDifference*yDifference) + (zDifference*zDifference));
    if (radiusSum < distance) return false;
    else return true;
}


void PhysicsEngine::collision_occurred(unsigned int s1, unsigned int s2)
{
    dynVector v1 = ObjList[s1].velocityVec;
    dynVector v2 = ObjList[s2].velocityVec;
    double massProduct1 = (-2 * ObjList[s2].objectMass) / (ObjList[s1].objectMass + ObjList[s2].objectMass);
    double massProduct2 = (-2 * ObjList[s1].objectMass) / (ObjList[s1].objectMass + ObjList[s2].objectMass);
    double dotProduct1 = ((v1 - v2) || (ObjList[s1].displaceVec - ObjList[s2].displaceVec));
    double dotProduct2 = ((v2 - v1) || (ObjList[s2].displaceVec - ObjList[s1].displaceVec));
    double norm = norm_mag(ObjList[s1].displaceVec - ObjList[s2].displaceVec);
    ObjList[s1].velocityVec = ((ObjList[s1].displaceVec - ObjList[s2].displaceVec) * massProduct1 * (dotProduct1) * (1/norm) + v1) * ObjList[s1].coefOfRest;
    ObjList[s2].velocityVec = ((ObjList[s2].displaceVec - ObjList[s1].displaceVec) * massProduct2 * (dotProduct2) * (1/norm) + v2) * ObjList[s2].coefOfRest;
    move_to_avoid_intersection(s1, s2);
}

void PhysicsEngine::move_to_avoid_intersection(unsigned int s1, unsigned int s2)
{
    double radiusSum = ObjList[s1].objectRadius + ObjList[s2].objectRadius;
    if (norm_mag(ObjList[s1].displaceVec) > norm_mag(ObjList[s2].displaceVec))
    {
        ObjList[s2].displaceVec = ObjList[s1].displaceVec + (ObjList[s2].get_velocity_unit_vector() * radiusSum);
    }
    else
    {
        ObjList[s1].displaceVec = ObjList[s2].displaceVec + (ObjList[s1].get_velocity_unit_vector() * radiusSum);
    }
    //ObjList[s1].displaceVec = ObjList[s1].previousDisplace;
    //ObjList[s2].displaceVec = ObjList[s2].previousDisplace;
}
