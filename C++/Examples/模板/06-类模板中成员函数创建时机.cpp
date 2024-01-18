#include <iostream>

using namespace std;

class Person1
{
public:
    void showPerson1()
    {
        cout << "show Person1" << endl;
    }
};

class Person1
{
public:
    void showPerson2()
    {
        cout << "show Person2" << endl;
    }
};

template <typename T>
class MyPerson
{
    T obj;

    void func1() 
    {
        obj.showPerson1();
    }

    void func2() 
    {
        obj.showPerson2();
    }
};

