#include "vector.hpp"
#include<iostream>
Vector::Vector(int n):matrix(n,1){}
Vector::Vector(matrix mat):matrix(mat){}
Vector Vector:: transform(matrix& other)
{
    return other*(*this);
}
double Vector :: dot(Vector& other){
    double result = 0;
    for(int i = 0 ; i < rows ; i++)
    {
        result += ((data[i][0])*other.data[i][0]);
    }
    return result;
}
