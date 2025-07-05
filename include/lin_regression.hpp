#pragma once
#include "vector.hpp"

class LinearRegression
{
    Matrix weights;
    Vector bias;
    double learning_rate;
    public:
    LinearRegression(int, int, int, double);
    void assign_weight(Matrix&);
    void assign_bias(Vector&);
    Vector predict(Vector&);
    Matrix predict(Matrix&);
    Vector compute_mse(Matrix&, Matrix& y);
    void train(Matrix& , Matrix& , int);
};