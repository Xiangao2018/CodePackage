#include <iostream>

using namespace std;

template<typename T> 
void Swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;    
}

int main() 
{
    double a = 10.3, b = 20.5;

    Swap(a, b);

    cout << a << " " << b << endl;
}