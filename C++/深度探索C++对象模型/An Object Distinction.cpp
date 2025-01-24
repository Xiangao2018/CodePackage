#include <iostream>

using namespace std;


class Animal {
public:
	void print() {
		std::cout << "Animal" << std::endl;
	}

	virtual void eat() {
		std::cout << "Anima eat" << std::endl;
	}
};

class Dog: public Animal {
public:
	void print() {
		std::cout << "Dog" << std::endl;
	}

	virtual void eat() {
		std::cout << "Dog eat" << std::endl;
	}
};

int main(int argc, char const *argv[])
{
	
	Animal a1;
	Dog d1;
	a1 = d1;
	a1.print(); // Animal
	d1.print(); // Dog


	Animal *a2 = new Dog;
	a2->print(); // Animal
	a2->eat(); // Dog eat

	Dog *d3 = dynamic_cast<Dog *>(a2);
	d3->print(); // Animal

	return 0;
}