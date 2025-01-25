#include <iostream>

using namespace std;

class Foo { // 为实现默构造函数
public:
	int val;
	Foo *pNext;
};

int main(int argc, char const *argv[])
{
	
	Foo f;
	std::cout << "val = " << f.val << ", pNext = " << f.pNext << std::endl;  // 此处的值并非 0，这是**程序的需要**，而不是**编辑器的需要**
	return 0;
}