#include "log_regression.hpp"
#include "function.hpp"
#include<iostream>

// Constructor for LogisticRegression, calls base LinearRegression constructor
LogisticRegression :: LogisticRegression(int num_outputvar , int num_features , int num_samples , double lr = 0.01) 
    : LinearRegression(num_outputvar,num_features,num_samples,lr){}

// Predict function: applies sigmoid activation to LinearRegression predictions
Matrix LogisticRegression :: predict(Matrix& X ){
    Matrix y_pred = LinearRegression::predict(X); // Get linear predictions
    y_pred.applyfunction(sigmoid);                // Apply sigmoid activation
    return y_pred;
}

// Compute binary cross-entropy loss for predictions and true labels
Vector LogisticRegression :: compute_bce(Matrix& y_pred , Matrix& y_true)
{
    Vector err(y_pred.get_nofcolumns());
    double epsilon = 1e-8; // For numerical stability
    for(int i = 0; i<y_pred.get_nofcolumns(); i++)
    {
        double sum = 0;
        int j = 0;
        for(; j<y_pred.get_nofrows();j++)
        {
            double ytrue = y_true(j,i);
            double ypred = y_pred(j,i);

            // Clamp predictions to avoid log(0)
            ypred = std::min(std::max(ypred, epsilon), 1 - epsilon);
            sum += (ytrue*log(ypred) + (1-ytrue)*log(1-ypred));
        }
        err(i,0,-sum / j); // Average BCE for column
    }
    return err;
}

// Train function: fits model using gradient descent
void LogisticRegression::train(Matrix& X, Matrix& y_true, int epochs) {
    int m = X.get_nofrows(); // number of training examples
    Vector bce(y_true.get_nofcolumns());
    for (int epoch = 0; epoch < epochs; ++epoch) {
        // 1. Predict with sigmoid activation
        Matrix y_pred = predict(X);  // applies sigmoid

        // 2. Error term: difference between prediction and true label
        Matrix error = y_pred + (y_true * -1);  // error = y_pred - y_true

        // 3. Compute gradients for weights
        Matrix dw = (X.transpose() * error) * (1.0 / m); // (n_features x n_output)

        bce = compute_bce(y_pred,y_true); // Compute BCE loss
        
        Vector db(y_pred.get_nofcolumns());

        // Print BCE every 100 epochs
        if(epoch % 100 == 0)
        {
            std::cout << "Epoch: " << epoch << " BCE: \n";
            bce.display();
        }
        // Compute gradients for bias
        for (int j = 0; j < error.get_nofcolumns(); j++) {
            double sum = 0;
            for (int i = 0; i < error.get_nofrows(); i++) {
                sum += error(i, j);
            }
            db(j, 0, sum / m);  // db = average over batch
        }

        // 4. Gradient descent updates for weights and bias
        weights = weights + (dw * -learning_rate);
        bias = Vector(bias + (db * -learning_rate));
    }
}
