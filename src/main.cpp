#include<iostream>
#include "matrix.hpp"
using namespace std;
int main()
{
    matrix m1(3,3);
    m1.fill(3.0);
    matrix m2 = m1;
    matrix m3 = m1*m2;
    matrix m4 = m3+m2;
    m4.display();
    return 0;
}