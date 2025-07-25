#pragma once
#include<cstdlib>
#include<ctime>
class Matrix {
protected:
  int rows, columns;
  double **data;
public:
  Matrix();
  Matrix(int, int);
  Matrix(const Matrix &other);
  ~Matrix();

  void fill(double value);
  void random_fill(double , double);
  Matrix transpose() const;
  Matrix operator+(const Matrix &other) const;
  Matrix operator*(const Matrix &other) const;
  Matrix& operator=(const Matrix &other);
  double operator()(int rowindex,int columnindex);
  void operator()(int rowindex,int columnindex , double data);
  Matrix get_row(int n);
  Matrix get_column(int n);
  int get_nofrows();
  int get_nofcolumns();
  void set_row(int n, Matrix &row);
  Matrix operator*(double scalar);
  double det();
  
  void applyfunction(double (*f)(double));

  void display();

protected:
  void allocatememory();
  void deallocatememory();
};