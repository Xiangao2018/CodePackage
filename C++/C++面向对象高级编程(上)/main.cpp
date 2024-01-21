#include <iostream>

using namespace std;

class Base 
{
public:
    Base(std::string name=""): name(name)
    {
        cout << "initialized"  << name << std::endl;
    }

    Base(const Base& other): name(other.name)
    {
        cout << "ctro" << std::endl;
    }

    Base& operator=(const Base& other)
    {
        cout << "===" << std::endl;
        this->name = other.name;

        return *this;
    }

private:
    std::string name;
};

int main(int argc, char **argv)
{
    Base *base = new Base(std::string("hello world"));    
    Base base1(*base);
    Base base2(std::string("hello 2")); 
    Base base3{std::string("hello 3")};

    // base = Base(std::string("eeee"));

    cout << __cplusplus << endl;
    return 0;
}