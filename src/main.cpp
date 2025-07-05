#include "Network.hpp"
#include "matrix.hpp"
#include "vector.hpp"
#include "lin_regression.hpp"
#include <iostream>

int main() {
  LinearRegression lr(2,2,2,0.01);
  Matrix X(2,2);
  X.random_fill(1,4);
  std:: cout << "X datas:\n" ;
  X.display();
  Matrix Y_true(2,2);
  Y_true.random_fill(1,5);
  std::cout << "Y_true datas:\n" ;
  Y_true.display();
  Matrix Y_predict = lr.predict(X);
  std::cout << "Y_predict datas (Before training):\n" ;
  Y_predict.display();
  lr.train(X,Y_true,1000);
  Y_predict = lr.predict(X);
  std::cout << "Y_predict datas (After Training) :\n";
  Y_predict.display();
  return 0;
}