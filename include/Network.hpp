#pragma once
#include "matrix.hpp"
#include <iostream>
#include <vector>

class Network {

public:
  std::vector<matrix> layers;
  int size;

  Network(std::vector<matrix> layers);

  void print();
};