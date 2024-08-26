#include <iostream>

void test01()
{
    auto lambd1 = []{
        std::cout << "Hello world " << std::endl;
    };
    lambd1();
}

void test02()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 10, 20, 30};
    
    std::for_each(vec.begin(), vec.end(), [](int i) {
        if( i % 5 == 0)
            std::cout << i << " ";
    });
    std::cout << std::endl;

    std::for_each(vec.begin(), vec.end(), [](int i) {
        if( i > 20 )
            std::cout << i << " ";
    });
    std::cout << std::endl;
}

void test03() 
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int sum = 0;
    std::for_each(vec.begin(), vec.end() , [&sum](int i) {
        sum += i;
    });

    std::cout << sum << std::endl;
}

void test04( std::vector<int> &number, std::function<void()> &printer) 
{
    int min = number.front();
    int max = number.front();
    
    for( auto i : number )
    {
        if ( i < min)
            min = i;
        if (i > max)
            max = i;
    }

    printer = [=](){
        std::cout << "min = " << min << std::endl;
        std::cout << "max = " << max << std::endl;
    };

}

int main(int argc, char const *argv[])
{   
    // test01();
    // test02();
    // test03();

    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::function<void()> printer;
    test04(vec, printer);

    printer();

    return 0;
}

