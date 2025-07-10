#include "lin_regression.hpp"
#include<iostream>
#include<cmath>

// Constructor for LinearRegression class
// Initializes weights and bias with random values, sets learning rate
LinearRegression :: LinearRegression(int num_outputvar , int num_features , int num_samples , double lr = 0.01) 
    : weights(num_features,num_outputvar), bias(num_outputvar), learning_rate(lr)
{
    weights.random_fill(0,1); // Randomly initialize weights
    bias.random_fill(0,1);    // Randomly initialize bias
    std::cout << "Weights" << '\n';
    weights.display();
    std::cout << "Bias" << '\n' ;
    bias.display();
}

// Assigns new weights to the model
void LinearRegression :: assign_weight(Matrix& assgn)
{
    weights = assgn;
}

// Assigns new bias to the model
void LinearRegression :: assign_bias(Vector& assgn)
{
    bias = assgn;
}

// Predicts output for given input X using current weights and bias
Matrix LinearRegression::predict(Matrix &X)
{
    Matrix Y = X*weights;  // Linear transformation

    // Add bias to each output
    for (int i = 0; i < Y.get_nofrows(); i++)    
    {
        for (int j = 0; j < Y.get_nofcolumns(); j++) 
        {
            double sum = Y(i,j);
            sum += bias(j,0);
            Y(i, j,sum);   // Set the value with bias added
        }
    }

    return Y; 
}

// Computes Mean Squared Error (MSE) between predictions and true values
Vector LinearRegression :: compute_mse(Matrix &y_pred, Matrix& y_true)
{
    Matrix errmatrix = y_true + (y_pred*-1); // Error matrix
    Vector error(errmatrix.get_nofcolumns());
    double err;
    for(int i = 0; i < errmatrix.get_nofcolumns(); i++)
    {
        err = 0;
        for(int j = 0; j < errmatrix.get_nofrows(); j++)
        {
            err += (errmatrix(j,i) * errmatrix(j,i)); // Sum of squared errors
        }
        err /= errmatrix.get_nofrows(); // Mean
        error(i,0,err);
    }
    return error;
}

// Trains the model using gradient descent for a given number of epochs
void LinearRegression :: train(Matrix& X, Matrix& y_true , int epoch)
{
    std::cout << "Inside train: \n";
    Vector mse(y_true.get_nofcolumns());
    for(int i = 0; i<epoch ; i++)
    {
        Matrix y_predict = predict(X); // Forward pass
        Matrix error = y_predict + (y_true*-1); // Compute error
        Matrix dw = (X.transpose()*error) * (2.0/X.get_nofrows()); // Gradient for weights
        Vector db(y_predict.get_nofcolumns());
        mse = compute_mse(y_predict, y_true); // Compute MSE
        if(i % 100 == 0)
        {
            std::cout << "Epoch: " << i << " MSE: \n";
            mse.display();
        }
        // Compute gradient for bias
        for(int j = 0; j<error.get_nofcolumns() ; j++)
        {
            double sum = 0;
            for(int k = 0 ; k<error.get_nofrows() ; k++)
            {
                sum += error(k,j);
            }
            db(j,0,sum);
        }
        // Update weights and bias using gradients and learning rate
        weights = weights + (dw * learning_rate * -1);
        bias = Vector(bias + (db * learning_rate * -1));
    }
}