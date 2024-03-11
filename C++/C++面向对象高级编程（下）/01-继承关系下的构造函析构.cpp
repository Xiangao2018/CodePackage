#include <iostream>

using namespace std;

class Base
{
public:
    Base() {
        cout << "base init" << endl;
    }

    ~Base() {
        cout << "base deinit" << endl;
    }
};

class Derived : public Base
{
public:
    Derived(): Base() {
        cout << "Derived init" << endl;
    }

    ~Derived() {
        cout << "Derived deinit" << endl;
    }
};


int main(int argc, char **argv)
{
    {
        Derived derived;
    }
}