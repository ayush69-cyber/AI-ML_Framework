#include "Network.hpp"

Network::Network(std::vector<matrix> layers) : layers(layers) {}

void Network::print() {

  for (int i = 0; i < layers.size(); i++) {
    layers.at(i).display();
  }
}