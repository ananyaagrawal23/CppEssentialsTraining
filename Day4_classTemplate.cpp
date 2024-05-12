#include<iostream>
#include<string>
using namespace std;

template <typename T> 
class Vector{
    T *items; 
    int size;
    int capacity;

public:
    Vector(){
        capacity = 5;
        size = 0;
        items = new T[capacity]; 
    }

    void push_back(const T& item){
        if(size < capacity){
            items[size++] = item; 
        }
        else{
            capacity *= 2;
            T *temp = new T[capacity];
            for(int i = 0; i < size; i++){
                temp[i] = items[i];
            }
            delete[] items;
            items = temp;
            items[size++] = item;
        }
    }

    T operator[](int index) const{
        if(index < 0 || index >= size){
            cout << "Index out of range." << endl;
            return T();
        }
        return items[index];
    }

    friend ostream& operator<<(ostream& os, const Vector<T>& v) {
        os << "[";
        for(int i = 0; i < v.size; i++) {
            os << v.items[i];
            if(i < v.size - 1)
                os << ", ";
        }
        os << "]";
        return os;
    }

    ~Vector() {
        delete[] items;
    }
};

class Device{
public:
    string name;

    friend ostream& operator<<(ostream& os, const Device& d) {
        os << d.name;
        return os;
    }
};

int main(){
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);

    Vector<string> vs;
    vs.push_back("Hello");
    vs.push_back("Hi");

    Vector<Device> vd;
    Device obj1;
    obj1.name = "D1";
    Device obj2;
    obj2.name = "D2";
    vd.push_back(obj1);
    vd.push_back(obj2);

    cout << "v: " << v << endl;
    cout << "vs: " << vs << endl;
    cout << "vd: " << vd << endl;

    return 0;
}
