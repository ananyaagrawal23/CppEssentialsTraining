#include<iostream>
#include<string>
using namespace std;

#define ADD(operandOne,operandTwo) ((operandOne)+(operandTwo)) 

template<typename T>

T add(T operandOne, T operandTwo){  // Function template
    return operandOne+operandTwo;
}

int main(){
    int result = add<int>(100,200); //template instantiation
    cout<<ADD(100,200)<<endl;
    cout<<result;
    string strResult = add<string>("Hello", "World!");
    cout<<strResult;
}