#include <string>
#include <iostream>

using namespace std;

template <class T>
void func(T a) {
    cout << "func" << endl;
}

template <class NameType, class AgeType = int>
class Person {
    public:
        Person(NameType name, AgeType age) {
            this->m_name = name;
            this->m_age = age;
        }
        NameType m_name;
        AgeType m_age;
        void showinfo() {
            cout << m_name << ", " << m_age<< endl;
        }
};

Person::Person(NameType name, AgeType age) {
    
}

template <class T1, class T2>
void func2(Person<T1, T2> p) {

}

int main(int argc, char const *argv[]) {
    Person<string> p;
    p.m_name = "张三";
    p.m_age = 18;
    p.showinfo();
    return 0;
}
