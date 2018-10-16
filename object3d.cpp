// Author: Benjamin Hilton
// October 2018

#include "physicsEngine.h"
#include "object3d.h"
#include <cmath>

void Object3D::update(double s)
{
    calculate_velocity_sign_vector();
    //dragForce = velocitySignVector * ((velocityVec * velocityVec) * 0.5 * fluidDensity * dragCoefficient * area);
    accelVec = accelVec + (dragForce * (1/objectMass));
    velocityVec = velocityVec + (accelVec * s);
    displaceVec = displaceVec + (velocityVec * s);
    collision_detect();
}

void Object3D::set_fluid_density(double density)
{
    fluidDensity = density;
}

void Object3D::set_mass(double mass)
{
    objectMass = mass;
}
void Object3D::set_radius(double radius)
{
    objectRadius = radius;
    area = (radius * radius) * 3.14159;
}

void Object3D::set_coefficient_of_restitution(double coef)
{
    coefOfRest = coef;
}

void Object3D::set_accel(double xAccel, double yAccel, double zAccel)
{
    accelVec.xValue = xAccel;
    accelVec.yValue = yAccel;
    accelVec.zValue = zAccel;
}

void Object3D::set_velocity(double xDot, double yDot, double zDot)
{
    velocityVec.xValue = xDot;
    velocityVec.yValue = yDot;
    velocityVec.zValue = zDot;
}

void Object3D::set_displace(double X, double Y, double Z)
{
    displaceVec.xValue = X;
    displaceVec.yValue = Y;
    displaceVec.zValue = Z;
}

void Object3D::calculate_velocity_sign_vector()
{
    if (velocityVec.xValue >=0) velocitySignVector.xValue = 1;
    if (velocityVec.xValue <0) velocitySignVector.xValue = -1;
    if (velocityVec.yValue >=0) velocitySignVector.yValue = 1;
    if (velocityVec.yValue <0) velocitySignVector.yValue = -1;
    if (velocityVec.zValue >=0) velocitySignVector.zValue = 1;
    if (velocityVec.zValue <0) velocitySignVector.zValue = -1;
}

void Object3D::collision_detect()
{
    double limit = 5 - objectRadius;
    if (displaceVec.xValue > limit)
    {
        velocityVec.xValue = -velocityVec.xValue*coefOfRest;
        displaceVec.xValue = limit;
    }
    if (displaceVec.yValue > limit)
    {
        velocityVec.yValue = -velocityVec.yValue*coefOfRest;
        displaceVec.yValue = limit;
    }
    if (displaceVec.zValue > limit)
    {
        velocityVec.zValue = -velocityVec.zValue*coefOfRest;
        displaceVec.zValue = limit;
    }
    if (displaceVec.xValue < -limit)
    {
        velocityVec.xValue = -velocityVec.xValue*coefOfRest;
        displaceVec.xValue = -limit;
    }
    if (displaceVec.yValue < -limit)
    {
        velocityVec.yValue = -velocityVec.yValue*coefOfRest;
        displaceVec.yValue = -limit;
    }
    if (displaceVec.zValue < -limit)
    {
        velocityVec.zValue = -velocityVec.zValue*coefOfRest;
        displaceVec.zValue = -limit;
    }
}
