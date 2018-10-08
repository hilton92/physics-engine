//Author: Benjamin Hilton


#include "dynVector.h"

dynVector::dynVector()
{
    x_value = 0.0;
    y_value = 0.0;
    z_value = 0.0;
}
dynVector::dynVector(double X, double Y, double Z)
{
    x_value = X;
    y_value = Y;
    z_value = Z;
}

dynVector::~dynVector()
{

}

void dynVector::setValues(double X, double Y, double Z)
{
    x_value = static_cast<double>(X);
    y_value = static_cast<double>(Y);
    z_value = static_cast<double>(Z);
}
