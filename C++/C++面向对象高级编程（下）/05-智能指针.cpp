#include <iostream>
#include <string>

using namespace std;

class IDoAction
{
public:
    virtual void doAction() = 0;
};

class RealAction : public IDoAction
{
private:
    void doAction()
    {
        std::cout << "Do Action" << std::endl;
    }
};

// class Base 
// {
// public:
//     Base(std::string n = "xiaoming"): name(n) {}

// private: 
//     std::string name;
// };

int main(int argc, char **argv)
{
    IDoAction *action = new RealAction();
    action->doAction();

    // RealAction rAction;
    // rAction.doAction();

    // Base *pBase = new Base();
    // std::shared_ptr<Base> p = std::shared_ptr<Base>(pBase);
    // std::shared_ptr<Base> p1 = std::shared_ptr<Base>(pBase);

    // cout << "p.usercount = " << p.use_count() << endl;
    // Base *pGetBase = p.get();
    // cout << "p.usercount = " << p.use_count() << endl;

    return 0;
}
