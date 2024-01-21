#include <iostream>
#include <string>

using namespace std;

string f1() { string s1 = "asdasdsa"; return s1; }
string f() { return "abcdefghijklmnopqrstuvw"; }

int main(int argc, char **argv)
{
    double v1 = 3.6;
    float v2 = 3.7;

    int v3 = v1 + v2;

    int v4 = v1 + 3;

    cout << v3 << " " << v4 << endl;

    const int &r2 = 42;

    cout << r2 << endl;

    int i = 42;
    const int &r1 = i;

    cout << f() << endl;
    
    const string &rf = f();

    string &rf1 = f1();

    cout << &"abcedef" << endl;

}