#include "matrix.hpp"
class Vector:public matrix
{
    protected:
    int dimension;
    public:
    Vector(int n);
    Vector(matrix);
    Vector transform(matrix&);
    double dot(Vector&);
};