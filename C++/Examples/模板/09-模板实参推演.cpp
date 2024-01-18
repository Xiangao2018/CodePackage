#include <iostream>

using namespace std;

template<typename T> 
void h(T *a)
{
    cout << "T = " << typeid(a).name() << endl;
}

template<> void h(int *a);

int main(int argc, char **argv)
{
    int b[6] = { 0, 1, 2, 3, 4, 5};

    h(b);

    return 0;
}