#include "Network.hpp"
#include "matrix.hpp"
#include "vector.hpp"
#include "lin_regression.hpp"
#include "log_regression.hpp"
#include <iostream>

int main() {
Matrix m1(3,3);
m1.fill(1);

Matrix m2(m1);

Matrix m3 (m2);

Matrix input(3,1);
input.fill(1);

std::vector<Matrix> layers;

layers.push_back(m1);
layers.push_back(m2);
layers.push_back(m3);

Network network(layers);
Matrix output = network.pump(input);
output.display();

return 0;
}