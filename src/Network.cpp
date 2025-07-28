#include "Network.hpp"

Network::Network(std::vector<Matrix> layers) : layers(layers) {}

void Network::print() {

  for (int i = 0; i < layers.size(); i++) {
    layers.at(i).display();
  }
}

Matrix Network::pump(Matrix input)
{
  Matrix temp(input);
  for(int i=0;i<layers.size();i++)
  {
    temp = layers.at(i)*temp;
  }
  return temp;
}