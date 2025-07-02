#include "matrix.hpp"
class Vector:public matrix
{
    protected:
    int dimension;
    public:
    Vector(int n);
    Vector(matrix);
    Vector transform(matrix&);
    double magnitude();
    void normalize();
    double dot(Vector&);
    Vector projectonto(Vector&);
    double angle_with(Vector&);
};