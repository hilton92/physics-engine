// Author: Benjamin Hilton
// Date: October 2018

#include "physicsEngine.h"

void PhysicsEngine::update(double s)
{
    velocityVec = velocityVec + (gravityVec * s);
    displaceVec = displaceVec + (velocityVec * s);
}

void PhysicsEngine::setVelocity(double x_dot, double y_dot, double z_dot)
{
    velocityVec.x_value = x_dot;
    velocityVec.y_value = y_dot;
    velocityVec.z_value = z_dot;
}

void PhysicsEngine::setGravity(double x_accel, double y_accel, double z_accel)
{
    gravityVec.x_value = x_accel;
    gravityVec.y_value = y_accel;
    gravityVec.z_value = z_accel;
}

void PhysicsEngine::setDisplace(double X, double Y, double Z)
{
    displaceVec.x_value = X;
    displaceVec.y_value = Y;
    displaceVec.z_value = Z;
}
