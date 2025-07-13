#pragma once
#include "vector.hpp"

class LinearRegression
{
    protected:
    Matrix weights;
    Vector bias;
    double learning_rate;
    public:
    LinearRegression(int, int, int, double);
    void assign_weight(Matrix&);
    void assign_bias(Vector&);
    Vector predict(Vector&);
    virtual Matrix predict(Matrix&);
    Vector compute_mse(Matrix&, Matrix& y);
    virtual void train(Matrix& , Matrix& , int);
};