#include <iostream>
#include <vector>

using namespace std;

class Base
{
public:
    virtual void Say() { cout << "Hello Base" << endl; }
};

class Sub: public Base
{
public:
    Sub(std::string name): name(name) {}
    virtual void Say() { cout << "hello Sub" << endl; }

    std::string getName() const { return name; }

private:
    std::string name;
};

int main(int argc, char **argv)
{

    Base b = Sub("小明");
    b.Say();

    std::vector<Sub *> iv;
    
    Sub *s1  = new Sub("小红");
    Sub *s2  = new Sub("小花");
    Sub *s3  = new Sub("小黄");
    Sub *s4  = new Sub("小黑");
    Sub *s5  = new Sub("小白");
    Sub *s6  = new Sub("小绿");
    Sub *s7  = new Sub("小紫");

    iv.push_back(s1);
    iv.push_back(s2);
    iv.push_back(s3);
    iv.push_back(s4);
    iv.push_back(s5);
    iv.push_back(s6);
    iv.push_back(s7);

    for (const auto &sub : iv)
    {
        cout << sub << " ";
    }
    cout << "before " << iv.size() << endl;

    iv[0] = nullptr;

    cout << "after " << iv.size() << endl;
    
    for (const auto &sub : iv)
    {
        cout << sub << " ";
    }

    return 0;
}