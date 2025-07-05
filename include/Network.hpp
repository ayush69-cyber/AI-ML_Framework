#pragma once
#include "matrix.hpp"
#include <iostream>
#include <vector>

class Network {

public:
  std::vector<Matrix> layers;
  int size;

  Network(std::vector<Matrix> layers);

  void print();
};