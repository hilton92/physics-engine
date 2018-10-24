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
        displaceVec{0,0,0},
        dragForce{0,0,0},
        gravityVec{0,0,0},
        objectRadius{1},
        coefOfRest{0.8},
        dragCoefficient{0.5},
        area{3.1415927},
        objectMass{1},
        fluidDensity{1.275},
        includeDrag{true}{}

    ~Object3D(){}
    dynVector accelVec;
    dynVector velocityVec;
    dynVector displaceVec;
    dynVector dragForce;
    dynVector velocitySignVector;
    dynVector gravityVec;
    dynVector previousDisplace;
    double objectRadius;
    double coefOfRest;
    double dragCoefficient;
    double area;
    double objectMass;
    double fluidDensity;
    bool includeDrag;
    void set_velocity(double xDot, double yDot, double zDot);
    void set_displace(double X, double Y, double Z);
    void set_accel(double xAccel, double yAccel, double zAccel);
    void set_gravity(double xAccel, double yAccel, double zAccel);
    void set_fluid_density(double density);
    void set_mass(double mass);
    void set_radius(double radius);
    void set_coefficient_of_restitution(double coef);
    void calculate_velocity_sign_vector();
    void update(double s);
    void collision_detect();
    dynVector get_velocity_unit_vector();
};

#endif
