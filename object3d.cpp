// Author: Benjamin Hilton
// October 2018

#include "physicsEngine.h"
#include "object3d.h"
#include <cmath>

void Object3D::update(double s)
{
    velocityVec = velocityVec + (accelVec * s);
    displaceVec = displaceVec + (velocityVec * s);
    collision_detect();
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

void Object3D::collision_detect()
{
    double limit = 5 - radius;
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