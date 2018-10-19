//Author: Benjamin Hilton

#ifndef DYNVECTOR_H_
#define DYNVECTOR_H_

#include <cmath>

class dynVector
{
public:
    double xValue;
    double yValue;
    double zValue;
    dynVector();
    dynVector(double X, double Y, double Z);
    ~dynVector();
    dynVector operator + (dynVector const &obj)
    {
        dynVector vec;
        vec.xValue = (xValue) + (obj.xValue);
        vec.yValue = (yValue) + (obj.yValue);
        vec.zValue = (zValue) + (obj.zValue);
        return vec;
    }

    dynVector operator - (dynVector const &obj)
    {
        dynVector vec;
        vec.xValue = (xValue) - (obj.xValue);
        vec.yValue = (yValue) - (obj.yValue);
        vec.zValue = (zValue) - (obj.zValue);
        return vec;
    }

    dynVector operator * (double scalar)
    {
        dynVector vec;
        vec.xValue = xValue * scalar;
        vec.yValue = yValue * scalar;
        vec.zValue = zValue * scalar;
        return vec;
    }

    dynVector operator * (dynVector const &obj)
    {
        dynVector vec;
        vec.xValue = (xValue) * (obj.xValue);
        vec.yValue = (yValue) * (obj.yValue);
        vec.zValue = (zValue) * (obj.zValue);
        return vec;
    }

    dynVector operator / (double scalar)
    {
        dynVector vec;
        vec.xValue = scalar / (this->xValue);
        vec.yValue = scalar / (this->yValue);
        vec.zValue = scalar / (this->zValue);
        return vec;
    }

    double operator || (dynVector const &obj)
    {
        double dotProduct{0};
        dotProduct = (this->xValue * obj.xValue) + (this->yValue * obj.yValue) + (this->zValue * obj.zValue);
        return dotProduct;
    }

    void set_values(double X, double Y, double Z);
};

double norm_2(dynVector input);

#endif
