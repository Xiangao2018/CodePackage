#include <iostream>

using namespace std;

template<typename T> 
bool myCompare(T &a, T &b)
{
    return a == b;
}

// 使用具体化的版本，具体化的优先调用
struct Person {
    std::string name;
    int age;

public:
    Person(std::string name, int age): name(name), age(age) {} 
};

template <> bool myCompare(Person &a, Person &b)
{
    return a.name == b.name && a.age == b.age;
}

int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 20;

    if (myCompare(a, b))
    {
        cout << "a == b" << endl;        
    }
    else
    {
        cout << "a != b" << endl;
    }

    Person p1 = Person("Tom", 11);
    Person p2 = Person("Tom", 12);

    if (myCompare(p1, p2))
    {
        cout << "p1 == p2" << endl;        
    }
    else
    {
        cout << "p1 != p2" << endl;
    }

    return 0;
}

