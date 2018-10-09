// Author: Benjamin Hilton
// October 2018

#include "physicsEngine.h"
#include "object3d.h"
#include <cmath>

void Object3D::update(double s)
{
    velocityVec = velocityVec + (accelVec * s);
    displaceVec = displaceVec + (velocityVec * s);
    collisionDetect();
}

void Object3D::setAccel(double x_accel, double y_accel, double z_accel)
{
    accelVec.x_value = x_accel;
    accelVec.y_value = y_accel;
    accelVec.z_value = z_accel;
}

void Object3D::setVelocity(double x_dot, double y_dot, double z_dot)
{
    velocityVec.x_value = x_dot;
    velocityVec.y_value = y_dot;
    velocityVec.z_value = z_dot;
}

void Object3D::setDisplace(double X, double Y, double Z)
{
    displaceVec.x_value = X;
    displaceVec.y_value = Y;
    displaceVec.z_value = Z;
}

void Object3D::collisionDetect()
{
    double limit = 5 - radius;
    if (displaceVec.x_value > limit)
    {
        velocityVec.x_value = -velocityVec.x_value*coefOfRest;
        displaceVec.x_value = limit;
    }
    if (displaceVec.y_value > limit)
    {
        velocityVec.y_value = -velocityVec.y_value*coefOfRest;
        displaceVec.y_value = limit;
    }
    if (displaceVec.z_value > limit)
    {
        velocityVec.z_value = -velocityVec.z_value*coefOfRest;
        displaceVec.z_value = limit;
    }
    if (displaceVec.x_value < -limit)
    {
        velocityVec.x_value = -velocityVec.x_value*coefOfRest;
        displaceVec.x_value = -limit;
    }
    if (displaceVec.y_value < -limit)
    {
        velocityVec.y_value = -velocityVec.y_value*coefOfRest;
        displaceVec.y_value = -limit;
    }
    if (displaceVec.z_value < -limit)
    {
        velocityVec.z_value = -velocityVec.z_value*coefOfRest;
        displaceVec.z_value = -limit;
    }
}
