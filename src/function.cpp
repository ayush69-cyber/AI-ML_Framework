#include "function.hpp"
double sigmoid(double x)
{
    return 1 / (1 + exp(-x));
}