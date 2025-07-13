#include "Network.hpp"
#include "matrix.hpp"
#include "vector.hpp"
#include "lin_regression.hpp"
#include "log_regression.hpp"
#include <iostream>

int main() {
LogisticRegression LR(1,2,4,0.1);
Matrix X(4, 2);
X.operator()(0,0,0);X.operator()(0,1,0);
X.operator()(1,0,0);X.operator()(1,1,1);
X.operator()(2,0,1);X.operator()(2,1,0);
X.operator()(3,0,1);X.operator()(3,1,1);
Matrix y_true(4,1);
y_true(0,0,0);
y_true(1,0,1);
y_true(2,0,1);
y_true(3,0,0);
Matrix y_predict = LR.predict(X);
std::cout << "Before Training: \n";
y_predict.display(); 
LR.train(X,y_true,1000);
std::cout << "After Training: \n";
y_predict = LR.predict(X);
y_predict.display();
return 0;
}