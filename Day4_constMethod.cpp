#include<iostream>
using namespace std;

class A{
    int x;
    public:
    void method(int x) const{
        this->x=100;
    }
};
