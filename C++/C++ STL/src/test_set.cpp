#include "test_set.h"
#include <string>
#include <cstdio>
#include <iostream>

namespace cpset {

    class Person {
    public:
        Person(std::string name): name(name) {}

        bool operator < (const Person & other) const { 
            return name < other.name;
        };

        std::string name;

    };

    void test_set() 
    {
        std::set<int> results;

        results.insert(10);
        results.insert(1);
        results.insert(20);
        results.insert(30);
        results.insert(15);

        for( auto i : results ) 
        {
            std::cout << i << std::endl;
        }
    }

    void test_class_in_set()
    {
        std::set<Person> results;

        results.insert(Person("hong"));
        results.insert(Person("hua2"));
        results.insert(Person("hua1"));

        for( auto i : results ) 
        {
            std::cout << i.name << std::endl;
        }
    }
}