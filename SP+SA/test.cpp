#include <iostream>
// #include <cstdlib>
using namespace std;


class Person{
    private:
    int m_age;
    int m_number;
    int m_hooj;

    public:
    void set_value(int age, int number, int hooj ){
        m_age = age;
        m_number = number;
        m_hooj = hooj;
    }
    
    void print(){
        cout << m_age <<endl;
        cout << m_number <<endl;
    }
    Person(){
        cout << "gouzao hanshu " << endl;
    }
};

int main()
{
    Person person1;

    char a[5];
    cout << sizeof(a);


int *p = new int[3]();
*p = 10;
delete p; 


    return 2;
}