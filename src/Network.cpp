#include "Network.hpp"

Network::Network(std::vector<Matrix> layers) : layers(layers) {}

void Network::print() {

  for (int i = 0; i < layers.size(); i++) {
    layers.at(i).display();
  }
}