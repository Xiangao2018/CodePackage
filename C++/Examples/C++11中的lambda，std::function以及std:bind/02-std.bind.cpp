#include <iostream>

using namespace std;

void printNumber(const std::vector<int> &number, std::function<bool(int i)> filter)
{
    for(auto i : number )
    {
        if( filter(i))
        {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;
}

bool isBetween(int i, int min, int max)
{
    return i >= min && i <= max;
}

int main(int argc, char const *argv[])
{
    std::vector<int> vec = {1, 2, 4, 5, 6, 7, 20, 30, 10, 25};

    printNumber(vec, [](int i) {
        return i % 5 == 0;
    });

    printNumber(vec, [](int i) {
        return i > 20;
    });

    std::function<bool(int i)> filter = std::bind(isBetween, placeholders::_1, 20, 40);
    printNumber(vec, filter);

    printNumber(vec, std::bind(isBetween, placeholders::_1, 20, 35));
    return 0;
}
