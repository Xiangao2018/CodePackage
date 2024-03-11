#include <iostream>

using namespace std;

class A {
public:
    virtual void vfunc1() { cout << "A::vfunc1" << endl; } 
    virtual void vfunc2() { cout << "A::vfunc2" << endl; } 

    void func1() { cout << "A::func1" << endl; } 
    void func2() { cout << "A::func2" << endl; } 

private:
    int m_data1, m_data2;
};

class B : public A {
public:
    virtual void vfunc1() { cout << "B::vfunc1" << endl; } 

    void func2() { cout << "B::func2" << endl; } 

    void func3() { func2(); vfunc1(); }; 

private:
    int m_data3;
};

class C: public B {
public:
    C(): m_data1(0), m_data4(10) {} 
    virtual void vfunc1() { cout << "C::vfunc1" << endl; } 
    void func2(){ cout << "C::func2" << endl; } 

    int data4() const { return m_data4; };
private:
    int m_data1, m_data4;
};

int main() {
    cout << "sizeof(int) = " << sizeof(int) << endl;
    cout << "sizeof(a) = " << sizeof(A)  << endl;
    cout << "sizeof(b) = " << sizeof(B)  << endl;
    cout << "sizeof(c) = " << sizeof(C)  << endl;

    C c;

    c.vfunc1();
    c.func2();
    c.vfunc2();

    c.func3();

    const C c2;

    cout << c.data4() << endl;
}