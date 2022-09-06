

#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Person;


template <class T1, class T2> 
void showPersonInfo(Person<T1, T2> p);

template <class T1, class T2>
class Person {

    friend void showPersonInfo<>(Person<T1, T2> p);
    
    friend void printPerson(Person<T1, T2> p){
        cout << p.m_name << ", " << p.m_age << endl; 
    }

    public:
    Person(T1 name, T2 age) {
        this->m_name = name;
        this->m_age = age;
    }

    private:
    T1 m_name;
    T2 m_age;
};

template <class T1, class T2> 
void showPersonInfo(Person<T1, T2> p) {
    cout << p.m_name << ", " << p.m_age << endl;
}

int main(int argc, char const *argv[])
{
    /* code */
    Person<string, int> p("zs", 18);

    showPersonInfo<>(p);

    printPerson(p);
    
    //printPerson(p);
    return 0;
}
