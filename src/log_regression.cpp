#include "log_regression.hpp"
#include "function.hpp"
#include<iostream>
LogisticRegression :: LogisticRegression(int num_outputvar , int num_features , int num_samples , double lr = 0.01) : LinearRegression(num_outputvar,num_features,num_samples,lr){}

Matrix LogisticRegression :: predict(Matrix& X ){
    Matrix y_pred = LinearRegression::predict(X);
    y_pred.applyfunction(sigmoid);
    return y_pred;
}

Vector LogisticRegression :: compute_bce(Matrix& y_pred , Matrix& y_true)
{
    Vector err(y_pred.get_nofcolumns());
    double epsilon = 1e-8;
    for(int i = 0; i<y_pred.get_nofcolumns(); i++)
    {
        double sum = 0;
        int j = 0;
        for(; j<y_pred.get_nofrows();j++)
        {
            double ytrue = y_true(j,i);
            double ypred = y_pred(j,i);

            ypred = std::min(std::max(ypred, epsilon), 1 - epsilon);
            sum += (ytrue*log(ypred) + (1-ytrue)*log(1-ypred));
        }
        err(i,0,-sum / j);
    }
    return err;
}
void LogisticRegression::train(Matrix& X, Matrix& y_true, int epochs) {
    int m = X.get_nofrows(); // number of training examples
    Vector bce(y_true.get_nofcolumns());
    for (int epoch = 0; epoch < epochs; ++epoch) {
        // 1. Predict with sigmoid activation
        Matrix y_pred = predict(X);  // applies sigmoid

        // 2. Error term
        Matrix error = y_pred + (y_true * -1);  // error = y_pred - y_true

        // 3. Compute gradients
        Matrix dw = (X.transpose() * error) * (1.0 / m); // (n_features x n_output)

        bce = compute_bce(y_pred,y_true);
        
        Vector db(y_pred.get_nofcolumns());

        if(epoch % 100 == 0)
        {
            std::cout << "Epoch: " << epoch << " BCE: \n";
            bce.display();
        }
        for (int j = 0; j < error.get_nofcolumns(); j++) {
            double sum = 0;
            for (int i = 0; i < error.get_nofrows(); i++) {
                sum += error(i, j);
            }
            db(j, 0, sum / m);  // db = average over batch
        }

        // 4. Gradient descent updates
        weights = weights + (dw * -learning_rate);
        bias = Vector(bias + (db * -learning_rate));
    }
}
