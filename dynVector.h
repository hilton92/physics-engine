//Author: Benjamin Hilton

#ifndef DYNVECTOR_H_
#define DYNVECTOR_H_


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

    dynVector operator * (double scalar)
    {
        dynVector vec;
        vec.xValue = xValue * scalar;
        vec.yValue = yValue * scalar;
        vec.zValue = zValue * scalar;
        return vec;
    }
    void set_values(double X, double Y, double Z);
};


#endif
