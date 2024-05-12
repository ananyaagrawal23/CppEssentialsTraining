#include<iostream>
#include<string>
using namespace std;

class Parent { 
private:
int q;
public:
Parent(int qArg){} //We have only parameterized constructor so default constructor is not created by compiler. But while inheritance, compiler searches for default constructor for the base class and it is not able to find it here.
    
};
class Child:public Parent {
private: int x;
public:
//Child(){} //This line gives error that there is no default constructor
Child():Parent::Parent(10){} //Now this will not give error
Child(int xArg):Parent::Parent(xArg){}

};

int main() {
    return 0;
}