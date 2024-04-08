#include "test_list.h"
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

namespace cplist {
    void test_list() 
    {
        list<int> l1;

        cout << "sizeof(l1) = " << sizeof(l1) << endl;

        l1.push_back(1);
    }
}