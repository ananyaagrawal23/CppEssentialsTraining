#include<iostream>
using namespace std;

int divFun(int numerator, int divisor){
    cout<<"Div Begin"<<endl;
    int result;
    try {
        result = numerator/divisor;
    }
    catch(...) {
        cout << "Exception" << endl;
    }
    cout<<"Div End"<<endl;
    return result;
}

void init()
{
    cout<<"Init Begin"<<endl;
    int result = divFun(10,0);
    cout<<"Init End"<<endl;
}

int main(){
    cout<<"Main Begin"<<endl;
    init();
    cout<<"Main End"<<endl;
}