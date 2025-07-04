#include "matrix.hpp"
#include<cmath>
#include<iostream>
void matrix::allocatememory()
{
    data = new double*[rows];
    for(int i = 0;i<rows;i++)
    {
        data[i] = new double[columns];
    }
}
void matrix::deallocatememory()
{
    for(int i = 0; i<rows;i++)
    {
        delete[] data[i];
    }
    delete data;
}
matrix::matrix(int r,int c) : rows(r),columns(c){
    allocatememory();
    fill(0.0);
}
matrix::matrix(const matrix& other):rows(other.rows), columns(other.columns)
{
    allocatememory();
    for(int i = 0; i<rows; i++)
    {
        for(int j = 0 ; j<columns ;j++)
        {
            data[i][j] = other.data[i][j];
        }
    }
}
matrix::~matrix()
{
    deallocatememory();
}
void matrix::fill(double value)
{
    for(int i = 0 ; i<rows ; i++)
    {
        for(int j = 0 ; j<columns ; j++)
        {
            data[i][j] = value;
            
        }
    }
}
matrix matrix::operator+(const matrix& other) const
{
    matrix c(rows,columns);
    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<columns ; j++)
        {
            c.data[i][j] = data[i][j] + other.data[i][j] ;
        }
    }
    return c;
}
matrix matrix:: operator*(const matrix& other) const
{
    if(columns == other.rows)
    {
    matrix c(rows,other.columns);
    c.fill(0.0);
    for(int i = 0 ; i<rows ; i++ )
    {
        for(int j = 0 ; j < other.columns; j++)
        {
            for(int k = 0; k < columns; k++)
            {
                c.data[i][j] += data[i][k]*other.data[k][j];
            }
        }
    }
    return c;
    }
}
matrix matrix::transpose()const
{
    matrix result(columns,rows);
    for(int i = 0; i<columns ;i++)
    {
        for(int j = 0; j<rows ; j++)
        {
            result.data[i][j] = data[j][i];
        }
    }
    return result;
}
double matrix::sigmoid(double x)
{
    return 1 / (1 + exp(-x));
}
void matrix::applyfunction(double (*f)(double), double value)
{
    for(int i = 0; i<rows ; i++)
    {
        for(int j = 0; j<rows ; j++)
        {
            data[i][j] = f(data[i][j]);
        }
    }
}
void matrix:: display()
{
    for(int i = 0; i<rows ; i++)
    {
        for(int j = 0; j<columns ; j++)
        {
            std::cout << data[i][j] << '\t';
        }
        std::cout<<std::endl;
    }
}