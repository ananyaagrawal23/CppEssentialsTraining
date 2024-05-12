#include<iostream>
#include<memory>
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
    std::unique_ptr<A> newSmartPtr =  std::make_unique<A>(); //Built in smart pointer
    newSmartPtr->operation();
}

int main()
{
    instantiate();
}