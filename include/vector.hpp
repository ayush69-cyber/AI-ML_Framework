#pragma once
#include "matrix.hpp"
class Vector : public Matrix
{
protected:
    int dimension;
public:
    Vector();
    Vector(int n);
    Vector(Matrix);
    Vector transform(Matrix&);
    double magnitude();
    void normalize();
    double dot(Vector&);
    Vector projectonto(Vector&);
    double angle_with(Vector&);
};