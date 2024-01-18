#include <iostream>
#include <string>

using namespace std;

template<typename NameType, typename AgeType = int>
struct Person
{
    Person(NameType name, AgeType age): name(name), age(age) {}

    NameType name;
    AgeType  age;
};

int main(int argc, char **argv)
{
    // 类模板没有自动类型推导 --- 类本身就是实例的模板
    // Person p1("Tom", 100);


    // 类模板在函数参数列表中可以有默认参数, AgeType 默认参数为 int
    Person<string> p2("David", 100);
}