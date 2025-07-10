#include "matrix.hpp"
#include<cmath>
#include<iostream>

// Allocates memory for the matrix data
void Matrix::allocatememory()
{
    data = new double*[rows];
    for(int i = 0; i < rows; i++)
    {
        data[i] = new double[columns];
    }
}

// Deallocates memory for the matrix data
void Matrix::deallocatememory()
{
    for(int i = 0; i < rows; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}

// Default constructor
Matrix::Matrix() : rows(0), columns(0){
    data = NULL;
}

// Constructor with row and column sizes
Matrix::Matrix(int r, int c) : rows(r), columns(c){
    allocatememory();
    fill(0.0);
}

// Copy constructor
Matrix::Matrix(const Matrix& other) : rows(other.rows), columns(other.columns)
{
    allocatememory();
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            data[i][j] = other.data[i][j];
        }
    }
}

// Destructor
Matrix::~Matrix()
{
    deallocatememory();
}

// Fills the matrix with a given value
void Matrix::fill(double value)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            data[i][j] = value;
        }
    }
}

// Fills the matrix with random values in [min_val, max_val]
void Matrix::random_fill(double min_val, double max_val)
{
    std::srand(std::time(0)); // Seed the RNG once

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            double r = static_cast<double>(std::rand()) / RAND_MAX; // [0,1]
            data[i][j] = min_val + r * (max_val - min_val);         // Scale to [min_val, max_val]
        }
    }
}

// Matrix addition
Matrix Matrix::operator+(const Matrix& other) const
{
    Matrix c(rows, columns);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            c.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return c;
}

// Matrix multiplication
Matrix Matrix::operator*(const Matrix& other) const
{
    Matrix c(rows, other.columns);
    c.fill(0.0);
    if(columns == other.rows)
    {
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < other.columns; j++)
            {
                for(int k = 0; k < columns; k++)
                {
                    c.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
    }
    else
    {
        std::cout << "Dimension Error" << std::endl;
    }
    return c;
}

// Assignment operator
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        // Deallocate old memory
        deallocatememory();

        // Copy dimensions
        rows = other.rows;
        columns = other.columns;

        // Allocate new memory
        allocatememory();

        // Copy data
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}

// Returns the transpose of the matrix
Matrix Matrix::transpose() const
{
    Matrix result(columns, rows);
    for(int i = 0; i < columns; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            result.data[i][j] = data[j][i];
        }
    }
    return result;
}

// Computes the determinant of the matrix
double Matrix::det()
{
    if(rows == 1 && columns == 1)
        return (data[0][0]);
    else if(rows == 2 && columns == 2)
        return ((data[0][0] * data[1][1]) - (data[1][0] * data[0][1]));
    else if(rows == columns)
    {
        Matrix m(rows-1, columns-1);
        double result = 0;
        for(int i = 0; i < columns; i++)
        {
            for(int j = 0; j < rows-1; j++)
            {
                int c = 0;
                for(int k = 0; k < columns; k++)
                {
                    if(k != i)
                    {
                        m.data[j][c] = data[j+1][k];
                        c++;
                    }
                }
            }
            result += (data[0][i] * m.det() * pow(-1, i));
        }
        return result;
    }
    else
    {
        std::cout << "Garbage Value Dimension error:" << std::endl;
        return -1;
    }
}

// Sigmoid activation function
double Matrix::sigmoid(double x)
{
    return 1 / (1 + exp(-x));
}

// Applies a function to each element of the matrix
void Matrix::applyfunction(double (*f)(double), double value)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            data[i][j] = f(data[i][j]);
        }
    }
}

// Scalar multiplication
Matrix Matrix::operator*(double scaler)
{
    Matrix temp = *this;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            temp.data[i][j] *= scaler;
        }
    }
    return temp;
}

// Element access (getter)
double Matrix::operator()(int rowindex, int columnindex)
{
    return data[rowindex][columnindex];
}

// Element access (setter)
void Matrix::operator()(int rowindex, int columnindex, double value)
{
    data[rowindex][columnindex] = value;
}

// Returns the nth row as a new matrix
Matrix Matrix::get_row(int n)
{
    Matrix m(1, columns);
    for(int i = 0; i < columns; i++)
    {
        m.data[0][i] = data[n][i];
    }
    return m;
}

// Returns the nth column as a new matrix
Matrix Matrix::get_column(int n)
{
    Matrix m(rows, 1);
    for(int i = 0; i < rows; i++)
    {
        m.data[i][0] = data[i][n];
    }
    return m;
}

// Sets the nth row to the values of another matrix
void Matrix::set_row(int n, Matrix& row)
{
    if(row.rows * row.columns != columns)
    {
        std::cout << "Dimension Error" << '\n';
        return;
    }
    for(int i = 0; i < columns; i++)
    {
        data[n][i] = (row.rows == 1) ? row.data[0][i] : row.data[i][0];
    }
}

// Returns the number of rows
int Matrix::get_nofrows()
{
    return rows;
}

// Returns the number of columns
int Matrix::get_nofcolumns()
{
    return columns;
}

// Displays the matrix to the console
void Matrix::display()
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            std::cout << data[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}