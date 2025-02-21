#include <iostream>

using namespace std;

template <class T> void h(T a) 
{
    cout << "T2 = " << typeid(a).name() << endl;
}

template <class T> void h1(const T &a)
{
    cout << "const T1 = " << typeid(a).name() << endl;
}

// template <class T> void h1(T &a) 
// {
//     cout << "T1 = " << typeid(a).name() << endl;
//     a = 10;
// }


int main(int argc, char **argv)
{
    // int b[6] = { 0, 1, 2, 3, 4, 5};

    // 1. 数组到指针的转换或函数到指针的转换
    // cout << "b = " << typeid(b).name() << endl; // b = A6_i 数组类型
    // h(b); // 输出： T2 = Pi ===> 数组类型转换为指针类型

    // 2. 限制修饰符的转换 
    int b1 = 3;
    h1(b1);
    std::cout << b1 << std::endl;

    const int b2 = 4;
    h1(b2);
    std::cout << b2 << std::endl;

    // 3. 基础类型的转换

    return 0;
}