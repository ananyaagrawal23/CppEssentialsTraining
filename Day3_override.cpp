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
    void accept(string text)override{ //now it will not compile if we don't mark base class as virtual
        cout<<"Numeric Derived class called"<<endl;
    }
};

class MaskedTextBox:public TextBox{
    public:
    //derived class method shadows base class method
    void accept(string text)override{ //now it will not compile if we don't mark base class as virtual
        cout<<"Masked Derived class called"<<endl;
    }
};

int main(){
    TextBox nameTextBox;
    nameTextBox.accept("Tom");

    NumericTextBox ageTextBox;
    ageTextBox.accept("25");

    TextBox* basePtr=&ageTextBox;
    basePtr->accept("35");

    MaskedTextBox phoneNumberTextBox;
    basePtr=&phoneNumberTextBox;

    basePtr->accept("+91-9844359120");
}
