#include "Network.hpp"
#include "matrix.hpp"
#include <iostream>
using namespace std;
int main() {
  matrix m1(3, 3);
  m1.fill(3.0);

  matrix m2 = m1, m3 = m1, m4 = m1;

  std::vector<matrix> layers;
  layers.push_back(m1);
  layers.push_back(m2);
  layers.push_back(m3);
  layers.push_back(m4);

  Network network(layers);

  network.print();
  return 0;
}