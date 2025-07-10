#include "matrix.hpp"
#include<cmath>
#include<iostream>
const float EPS=1e-9;

void Matrix::allocatememory()
{
    data = new double*[rows];
    for(int i = 0;i<rows;i++)
    {
        data[i] = new double[columns];
    }
}
void Matrix::deallocatememory()
{
    for(int i = 0; i<rows;i++)
    {
        delete[] data[i];
    }
    delete data;
}
Matrix::Matrix() : rows(0),columns(0){
    data = NULL;
}
Matrix::Matrix(int r,int c) : rows(r),columns(c){
    allocatememory();
    fill(0.0);
}
Matrix::Matrix(const Matrix& other):rows(other.rows), columns(other.columns)
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
Matrix::~Matrix()
{
    deallocatememory();
}
void Matrix::fill(double value)
{
    for(int i = 0 ; i<rows ; i++)
    {
        for(int j = 0 ; j<columns ; j++)
        {
            data[i][j] = value;
            
        }
    }
}
void Matrix::random_fill(double min_val = -1 , double max_val = 1)
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
Matrix Matrix::operator+(const Matrix& other) const
{
    Matrix c(rows,columns);
    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<columns ; j++)
        {
            c.data[i][j] = data[i][j] + other.data[i][j] ;
        }
    }
    return c;
}
Matrix Matrix:: operator*(const Matrix& other) const
{
    if(columns == other.rows)
    {
    Matrix c(rows,other.columns);
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
Matrix Matrix::transpose()const
{
    Matrix result(columns,rows);
    for(int i = 0; i<columns ;i++)
    {
        for(int j = 0; j<rows ; j++)
        {
            result.data[i][j] = data[j][i];
        }
    }
    return result;
}
double Matrix::det()
{
    if(rows == 1 && columns== 1)
            return (data[0][0]);
        else if(rows == 2 && columns == 2)
            return ((data[0][0] * data[1][1]) - (data[1][0]*data[0][1]));
        else if(rows == columns)
        {
            Matrix m(rows-1,columns-1);
            double result = 0;
            for(int i = 0; i<columns ; i++)
            {
                for(int j = 0; j<rows-1 ; j++)
                {
                    int c = 0;
                    for(int k = 0 ; k < columns ; k++)
                    {
                        if(k!=i)
                        {
                            m.data[j][c] = data[j+1][k];
                            c++;
                        }
                    }
                }
                result += (data[0][i] * m.det() * pow(-1,i));
            }
            return result;
        }
        else
        {
            std::cout << "Garbage Value Dimension error:" << std::endl;
            return -1;
        }
}
double Matrix::sigmoid(double x)
{
    return 1 / (1 + exp(-x));
}
void Matrix::applyfunction(double (*f)(double), double value)
{
    for(int i = 0; i<rows ; i++)
    {
        for(int j = 0; j<rows ; j++)
        {
            data[i][j] = f(data[i][j]);
        }
    }
}
Matrix Matrix:: operator*(double scaler)
{
    Matrix temp = *this;
    for(int i = 0 ; i<rows; i++)
    {
        for(int j = 0 ; j<columns ; j++)
        {
            temp.data[i][j]*=scaler;
        }
    }
    return temp;
}
double Matrix:: operator()(int rowindex,int columnindex)
{
    return data[rowindex][columnindex];
}
void Matrix:: operator()(int rowindex , int columnindex , double value)
{
    data[rowindex][columnindex]= value;
}
Matrix Matrix::get_row(int n)
{
    Matrix m(1,columns);
    for(int i = 0; i <columns ; i++)
    {
        m.data[0][i] = data[n][i];
    }
    return m;
}
Matrix Matrix::get_column(int n)
{
    Matrix m(rows,1);
    for(int i = 0; i <rows ; i++)
    {
        m.data[i][0] = data[i][n];
    }
    return m;
}
void Matrix::set_row(int n , Matrix& row)
{
    if(row.rows*row.columns != columns)
    {
        std:: cout << "Dimension Error" << '\n';
        return;
    }
    for(int i = 0; i < columns ; i++)
    {
        data[n][i] = (row.rows == 1)?row.data[0][i]:row.data[i][0];
    }
}
int Matrix :: get_nofrows()
{
    return rows;
}
int Matrix :: get_nofcolumns()
{
    return columns;
}
int Matrix::rank() {
    Matrix temp = *this;  
    int rank = 0;
    int noofrow = temp.get_nofrows();
    int noofcol = temp.get_nofcolumns();

    for (int col = 0, row = 0; col < noofcol && row < noofrow; col++) {
        int pivot = row;

    
        for (int i = row; i < noofrow; i++) {
            if (std::fabs(temp(i, col)) > std::fabs(temp(pivot, col))) {
                pivot = i;
            }
        }

        
        if (std::fabs(temp(pivot, col)) < EPS)
            continue;

        if (pivot != row) {
            for (int k = 0; k < noofcol; k++) {
                double tmp = temp(row, k);
                temp(row, k, temp(pivot, k));
                temp(pivot, k, tmp);
            }
        }

        for (int i = row + 1; i < noofrow; i++) {
            double factor = temp(i, col) / temp(row, col);
            for (int j = col; j < noofcol; j++) {
                double newVal = temp(i, j) - factor * temp(row, j);
                temp(i, j, newVal);
            }
        }

        ++row;
        ++rank;
    }

    return rank;
}

    


void Matrix:: display()
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