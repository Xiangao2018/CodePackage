#include "Complex.h"
#include <iostream>

using namespace std;

int main() {
    Complex c1(1, 2), c2(3, 4);
    Complex c3 = c1 + c2;

    std::cout << "c3 = " << c3.real() << " + " << c3.imag() << "i" << std::endl;

    return 0;
}