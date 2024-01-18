#include <iostream>

using namespace std;

// 1. 如果普通函数和函数模板都可以实现，优先调用普通函数
void myPrint(int a, int b)
{
    cout << "调用普通的函数" << endl;
}

template<typename T> 
void myPrint(T a, T b)
{
    cout << "调用模板函数" << endl;
}

template<typename T> 
void myPrint(T a, T b, T c)
{
    cout << "调用重载的模板函数" << endl;
}


int main(int argc, char **argv)
{
    int a = 10;
    int b = 20;
    // 1. 如果普通函数和函数模板都可以实现，优先调用普通函数
    myPrint(a, b);

    // 2. 可以通过**空模板参数列表**来强制调用函数模板；
    myPrint<>(a, b);

    // 3. 函数模板也可以发生重载
    myPrint(a, b, 100);

    // 4. 如果函数模板可以产生更好的匹配，优先调用函数模板；
    char c = 'a';
    char d = 'b';
    myPrint(c, d);
}