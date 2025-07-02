#include "Network.hpp"
#include "matrix.hpp"
#include "vector.hpp"
#include <iostream>

int main() {
  matrix m1(3,3);
  m1.fill(3);
  Vector v1(3);
  v1.fill(2);
  Vector v2 = v1.transform(m1);
  v2.display();
  std::cout << v1.dot(v2);
  return 0;
}