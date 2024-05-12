#include<iostream>
#include<string>
using namespace std;

class TextBox{
    public:
    void accept(string text){
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
    basePtr->accept("35"); //expect to call derived but calls base
}

//when using shadowing, don't use substitution, it will fail
//Always use object or pointer of derived only