#include "vector.hpp"
#include<cmath>
#include<iostream>

// Default constructor: Initializes a Vector as a Matrix with default constructor
Vector::Vector():Matrix(){}

// Constructor: Initializes a Vector of size n (n x 1 matrix)
Vector::Vector(int n):Matrix(n,1){}

// Constructor: Initializes a Vector from a Matrix if it's a column matrix
Vector::Vector(Matrix mat):Matrix(mat.get_nofrows()*mat.get_nofcolumns(),1){
    if (mat.get_nofcolumns() != 1) {
        std::cerr << "Error: Vector can only be initialized from column matrix.\n";
        std::exit(EXIT_FAILURE);
    }

    // Copy data from the matrix to the vector
    for (int i = 0; i < mat.get_nofrows(); i++) {
        data[i][0] = mat(i, 0);
    }
}

// Applies a transformation matrix to this vector and returns the result
Vector Vector:: transform(Matrix& other)
{
    return other*(*this);
}

// Computes the dot product with another vector
double Vector :: dot(Vector& other){
    double result = 0;
    for(int i = 0 ; i < rows ; i++)
    {
        result += ((data[i][0])*other.data[i][0]);
    }
    return result;
}

// Computes the magnitude (Euclidean norm) of the vector
double Vector:: magnitude()
{
    double result = 0;
    for(int i = 0 ; i<rows ; i++)
    {
        result += (data[i][0] * data[i][0]);
    }
    return pow(result,0.5);
}

// Normalizes the vector (makes its magnitude 1)
void Vector:: normalize()
{
    double mag = magnitude();
    for(int i = 0; i<rows ; i++)
    {
        data[i][0]/=mag;
    }
}

// Projects this vector onto another vector and returns the result
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

// Computes the angle (in radians) between this vector and another vector
double Vector::angle_with(Vector& other)
{
    return acos(dot(other)/(magnitude()*other.magnitude()));
}