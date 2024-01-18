#include <iostream>
#include <string>

using namespace std;

template <typename NameType, typename AgeType> 
class Person 
{
public:
    Person(NameType name, AgeType age) : name(name), age(age) {}

    NameType name;
    AgeType age;
};

int main(int argc, char **argv)
{
    Person<string, int> p1("Tom", 100);
    Person<string, int> p2("Tom", 101);
}