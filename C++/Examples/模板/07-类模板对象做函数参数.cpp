#include <iostream>
#include <string>

using namespace std;

template<typename NameType, typename AgeType> 
class Person
{
public:
    Person(NameType name, AgeType age): name(name), age(age) {}

    NameType name;
    AgeType age;
};

// 1. 直接指定参数类型
void showPerson(Person<string, int> &p)
{
    cout << "1 name = " << p.name << " age = " << p.age << endl;
}

// 2.参数模板化
template<typename NameType, typename AgeType>
void showPerson(Person<NameType, AgeType> &p)
{
    cout << "2 name = " << p.name << " age = " << p.age << endl;
}

// 3. 这个类模板化
template <typename T>
void showPerson(T &p)
{
    cout << "3 name = " << p.name << " age = " << p.age << endl;
}

int main(int argc, char**argv)
{
    Person<string, int> p1("孙悟空", 100);

    showPerson(p1);
}