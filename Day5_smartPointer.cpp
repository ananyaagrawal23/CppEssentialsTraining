#include<iostream>
using namespace std;

class A{
    public:
    A(){cout <<"A const"<<endl;}
    ~A(){cout <<"A dest"<<endl;}
    void operation(){ 
        cout<<"A.operation called"<<endl;
    }
};

template <typename T>  // Now smart pointer is reusable
class SmartPtrOfAnyType{
    T *ptr;
    public:
    SmartPtrOfAnyType(T* ptrRef):ptr{ptrRef}{} //inject address of object
    ~SmartPtrOfAnyType(){
        delete ptr;
    }
    T* operator->(){ //operator overloading of unary operator ->
        return ptr;
    }
};

void instantiate(){
    SmartPtrOfAnyType<A> smartPtr {new A()};
    smartPtr->operation();
}

int main()
{
    instantiate();
}