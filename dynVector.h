//Author: Benjamin Hilton

#ifndef DYNVECTOR_H_
#define DYNVECTOR_H_


class dynVector
{
public:
    double x_value;
    double y_value;
    double z_value;
    dynVector();
    dynVector(double X, double Y, double Z);

    ~dynVector();
    dynVector operator + (dynVector const &obj)
    {
        dynVector vec;
        vec.x_value = (x_value) + (obj.x_value);
        vec.y_value = (y_value) + (obj.y_value);
        vec.z_value = (z_value) + (obj.z_value);
        return vec;
    }

    dynVector operator * (double scalar)
    {
        dynVector vec;
        vec.x_value = x_value * scalar;
        vec.y_value = y_value * scalar;
        vec.z_value = z_value * scalar;
        return vec;
    }


    void setValues(double X, double Y, double Z);

};


#endif
