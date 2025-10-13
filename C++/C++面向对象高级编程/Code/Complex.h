#ifndef __COMPLEX__
#define __COMPLEX__

class Complex {

public:
    Complex(double r = 0, double i = 0);
    Complex& operator+(const Complex &c);    

    double real() const { return re; }
    double imag() const { return im; }

private:
    double re, im;
};

#endif // __COMPLEX__




