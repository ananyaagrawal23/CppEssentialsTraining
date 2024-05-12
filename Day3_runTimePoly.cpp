#include<iostream>
#include<string>
using namespace std;

class TextBox{
    public:
    virtual void accept(string text){ //Run time polymorphism by adding virtual. Also called late binding
        cout<<"Base class called"<<endl;
    }
};

class NumericTextBox:public TextBox{
    public:
    //derived class method shadows base class method
    void accept(string text){
        cout<<"Derived class called"<<endl;
    } //Shadowing 
};

int main(){
    TextBox nameTextBox;
    nameTextBox.accept("Tom");

    NumericTextBox ageTextBox;
    ageTextBox.accept("25");

    TextBox* basePtr=&ageTextBox;
    basePtr->accept("35");
}
