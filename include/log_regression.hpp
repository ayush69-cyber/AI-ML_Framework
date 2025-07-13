#pragma once
#include "lin_regression.hpp"

class LogisticRegression : public LinearRegression{
    public:
    LogisticRegression(int , int , int, double);
    Matrix predict(Matrix&) override;
    Vector compute_bce(Matrix& , Matrix&);
    void train(Matrix&,Matrix&,int) override;
};