
#include <iostream>
using namespace std;

template <class T>
class MyArray{
    public:
        MyArray(int capacity) {
            cout << "有参构造函数调用" << endl;
            m_capacity = capacity;
            m_arr = new T[capacity];
            m_size = 0;
        }

        MyArray(const MyArray<T> &arr) {
            cout << "拷贝构造函数调用" << endl;
            // 回收堆区内存;
            // if (this->m_arr != NULL) {
            //     delete this->m_arr;
            // }

            this->m_arr = new T[arr.m_capacity];
            this->m_capacity = arr.m_capacity;
            this->m_size = arr.m_size;

            for (int i = 0; i < arr.m_size; i++) {
                this->m_arr[i] = arr.m_arr[i];
            }
        }

        void operator=(const MyArray<T> &arr) {
            // 回收堆区内存;
            cout << "等号运算符重载" << endl;
            if (this->m_arr != NULL) {
                delete this->m_arr;
            }

            this->m_arr = new T[arr.m_capacity];
            this->m_capacity = arr.m_capacity;
            this->m_size = arr.m_size;

            for (int i = 0; i < arr.m_size; i++) {
                this->m_arr[i] = arr.m_arr[i];
            }
        }

        ~MyArray() {
            cout << "析构函数调用" << endl;
            delete m_arr;
        }

        int getCapacity() {
            return m_capacity;
        }
        int getSize() {
            return m_size;
        }

        void append(T t) {
            if (this->m_size == this->m_capacity) {
                T *arr = this->m_arr;
                this->m_arr = new T[m_capacity + 10];
                this->m_capacity += 10;

                for (int i = 0; i < this->m_size; i++) {
                    this->m_arr[i] = arr[i];
                }
                delete arr;
            }

            this->m_arr[m_size++] = t;
        }

        T pop() {
            T t = m_arr[--m_size];

            if ((m_capacity - m_size) > 10) {
                T arr[] = new T[m_size + 5];
                m_capacity = m_size + 5;
            }
            return t;
        }

        void show() {
            cout << "show 函数调用" << endl;
            for (int i = 0; i < this->m_size; i++) {
                cout << m_arr[i] << endl;
            }
            cout << "show 函数调用退出" << endl;
        }


    private:
        int m_capacity;
        int m_size;
        T *m_arr;
};

int main(int argc, char const *argv[])
{
    MyArray<int> myArray(5);
    MyArray<int> myArray2 = myArray;

    myArray2 = myArray;

    myArray.append(1);
    myArray.append(2);
    myArray.append(3);
    myArray.append(4);
    myArray.append(5);
    myArray.show();
    for(int i = 0; i < 5; i++) {
        int num = myArray.pop();
        cout << "pop:" << num << endl;
    }
    return 0;
}
