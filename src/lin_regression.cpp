#include "lin_regression.hpp"
#include<iostream>
#include<cmath>
LinearRegression :: LinearRegression(int num_outputvar , int num_features , int num_samples , double lr = 0.01) : weights(num_features,num_outputvar),bias(num_outputvar),learning_rate(lr)
{
    weights.random_fill(0,1);
    bias.random_fill(0,1);
    std::cout << "Weights" << '\n';
    weights.display();
    std::cout << "Bias" << '\n' ;
    bias.display();
}
void LinearRegression :: assign_weight(Matrix& assgn)
{
    weights = assgn;
}
void LinearRegression :: assign_bias(Vector& assgn)
{
    bias = assgn;
}
Matrix LinearRegression::predict(Matrix &X)
{
    Matrix Y = X*weights;  

    
    for (int i = 0; i < Y.get_nofrows(); i++)    
    {
        for (int j = 0; j < Y.get_nofcolumns(); j++) 
        {
            double sum = Y(i,j);
            sum += bias(j,0);
            Y(i, j,sum);   
        }
    }

    return Y; 
}
Vector LinearRegression :: compute_mse(Matrix &y_pred, Matrix& y_true)
{
    Matrix errmatrix = y_true + y_pred*-1;
    Vector error(errmatrix.get_nofcolumns());
    double err;
    for(int i = 0; i < errmatrix.get_nofcolumns(); i++)
    {
        err = 0;
        for(int j = 0; j < errmatrix.get_nofrows(); j++)
        {
            err += (errmatrix(j,i) * errmatrix(j,i));
        }
        err /= errmatrix.get_nofrows();
        error(i,0,err);
    }
    return error;
}
void LinearRegression :: train(Matrix& X, Matrix& y_true , int epoch)
{
    std::cout << "Inside train: \n";
    for(int i = 0; i<epoch ; i++)
    {
        Matrix y_predict = predict(X);
        Matrix error = y_predict + (y_true*-1);
        Matrix dw = (X.transpose()*error) * (2.0/X.get_nofrows());
        Vector db(y_predict.get_nofcolumns());
        for(int j = 0; j<error.get_nofcolumns() ; j++)
        {
            double sum = 0;
            for(int k = 0 ; k<error.get_nofrows() ; k++)
            {
                sum += error(k,j);
            }
            db(j,0,sum);
        }
        weights = weights + (dw * -learning_rate);
        bias = bias + (db*-learning_rate);
    }
}