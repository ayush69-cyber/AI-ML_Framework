#include "vector.hpp"
#include<cmath>
#include<iostream>
Vector::Vector():Matrix(){}
Vector::Vector(int n):Matrix(n,1){}
Vector::Vector(Matrix mat):Matrix(mat.get_nofrows()*mat.get_nofcolumns(),1){
    for(int i = 0; i<mat.get_nofrows();i++)
    {
        for(int j = 0 ; j < mat.get_nofcolumns(); j++)
        {
            data[i+j][0] = mat(i,j);
        }
    }
}
Vector Vector:: transform(Matrix& other)
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
double Vector:: magnitude()
{
    double result = 0;
    for(int i = 0 ; i<rows ; i++)
    {
        result += (data[i][0] * data[i][0]);
    }
    return pow(result,0.5);
}
void Vector:: normalize()
{
    double mag = magnitude();
    for(int i = 0; i<rows ; i++)
    {
        data[i][0]/=mag;
    }
}
Vector Vector::projectonto(Vector& other)
{
    
    Vector temp(rows);
    double scalar = dot(other)/(other.magnitude()*other.magnitude());
    for(int i = 0; i<rows ; i++)
    {
        temp.data[i][0] = other.data[i][0] * scalar;
        
    }
    return temp;
}
double Vector::angle_with(Vector& other)
{
    return acos(dot(other)/(magnitude()*other.magnitude()));
}