#include <iostream>

using namespace std;

class X {};
class Y : public virtual X {};
class Z : public virtual X {};
class A : public Y, public Z {};

int main(int argc, char const *argv[])
{
	
	X x;
	Y y;
	Z z;
	A a;

	std::cout << "sizeof(x) = " << sizeof(x) << std::endl; // 1
	std::cout << "sizeof(y) = " << sizeof(y) << std::endl; // 8
	std::cout << "sizeof(z) = " << sizeof(z) << std::endl; // 8
	std::cout << "sizeof(a) = " << sizeof(a) << std::endl; // 16

	return 0;
}