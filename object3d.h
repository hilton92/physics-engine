//Author: Benjamin Hilton

#ifndef OBJECT3D_H_
#define OBJECT3D_H_

#include "dynVector.h"

class Object3D
{
public:
    Object3D() :
        accelVec{0,0,0},
        velocityVec{0,0,0},
        displaceVec{0,0,0} {}
    ~Object3D(){}
    dynVector accelVec;
    dynVector velocityVec;
    dynVector displaceVec;
    dynVector dragForce;
    dynVector velocitySignVector;
    double objectRadius = 1;
    double coefOfRest = 0.8;
    double dragCoefficient = 0.5;
    double area = 0;
    double objectMass = 1;
    double fluidDensity = 0;
    void set_velocity(double xDot, double yDot, double zDot);
    void set_displace(double X, double Y, double Z);
    void set_accel(double xAccel, double yAccel, double zAccel);
    void set_fluid_density(double density);
    void set_mass(double mass);
    void set_radius(double radius);
    void set_coefficient_of_restitution(double coef);
    void calculate_velocity_sign_vector();
    void update(double s);
    void collision_detect();
};

#endif
