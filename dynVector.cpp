//Author: Benjamin Hilton


#include "dynVector.h"

dynVector::dynVector()
{
    xValue = 0.0;
    yValue = 0.0;
    zValue = 0.0;
}
dynVector::dynVector(double X, double Y, double Z)
{
    xValue = X;
    yValue = Y;
    zValue = Z;
}

dynVector::~dynVector()
{

}

void dynVector::set_values(double X, double Y, double Z)
{
    xValue = static_cast<double>(X);
    yValue = static_cast<double>(Y);
    zValue = static_cast<double>(Z);
}

double norm_2(dynVector input)
{
    return sqrt((input.xValue*input.xValue) + (input.yValue*input.yValue) + (input.zValue*input.zValue));
}
