#include <iostream>
#include <string>

using namespace std;


class ZooAnimal {
public:
	ZooAnimal(string _name = "") : name(_name) {};
	virtual ~ZooAnimal() {} ;

	virtual void rotate() { std::cout << "ZooAnimal Rotate" << std::endl; }

public:
	int loc;
	string name;
};

class Bear : public ZooAnimal {
public:
	Bear(string name = "") : ZooAnimal(name) { };
	~Bear() {} ;

	void rotate() override { std::cout << "Bear Rotate" << std::endl; }
	virtual void dance() {}  ;

public:
	enum Dance
	{
		
	};

	Dance dances_known;
	int cell_block;
};




int main(int argc, char const *argv[])
{
	// Bear b("Yogi");
	// Bear *pb = &b;
	// Bear &rb = *pb;

	Bear b1("Yogi");
	ZooAnimal *pz = &b1;
	Bear *pb = &b1;

	std::cout << "&b1" << &b1 << std::endl; // &b10x16b5735e0
	std::cout << "&pz" << &pz << ", pz = "  << pz << std::endl; // &pz0x16b5735b0, pz = 0x16b5735e0
	std::cout << "pb" << &pb << ", pb = "  << pb << std::endl;	// pb0x16b5735a8, pb = 0x16b5735e0

	std::cout << "sizeof(int *) = " << sizeof(int *) << std::endl;
	std::cout << "&loc = " << &(b1.loc) << std::endl;
	std::cout << "&name = " << &(b1.name) << std::endl;
	std::cout << "&cell_block = " << &(b1.cell_block) << std::endl;
	std::cout << "&dances_known = " << &(b1.dances_known) << std::endl;




	return 0;
}