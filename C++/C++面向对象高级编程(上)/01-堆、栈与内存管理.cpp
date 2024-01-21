#include <iostream>

using namespace std;

class Student 
{   
    Student(int age = 0, int no = 0) : age(age), no(no)
    {

    }
private:
    double age;
    double no;
};



class MyString 
{
    MyString(const char *cstr = 0)
    {
        if( cstr) {
            m_data = new char[strlen(cstr) + 1];
            strcpy(m_data, cstr);
        } 
        else {
            m_data = new char[1];
            *m_data = '\0';
        }
    }
private:
    char *m_data;
};

int main(int argc, char **argv)
{
    cout << sizeof(Student) << endl;
    cout << sizeof(MyString) << endl;

    return 0;
}