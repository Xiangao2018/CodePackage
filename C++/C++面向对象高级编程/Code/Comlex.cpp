#include "Complex.h"

Complex::Complex(double r, double i) : re(r), im(i) {}

Complex& Complex::operator+(const Complex &c) {
    re += c.re;
    im += c.im;
    return *this;
}