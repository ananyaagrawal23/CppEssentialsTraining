#include<iostream>
#include<string>
using namespace std;

void f1(string arg){
    arg = "Hello";
}

// void f2_0(string *arg){
//     *arg="Hello Pointer";
// }
void f2_1(const string* arg){ //const correctness. R->L, arg is ptr through which accessing the string which is const, so can't modify the string. But we can modify the pointer.
    //*arg="Hello Pointer";
    string temp ="jsdvbfg";
    arg = &temp;
}
void f2_2(string* const arg){ //const correctness. R->L, Now arg is ptr which is const so can't modify the pointer but can modify the value pointer by it.
    *arg="Hello Pointer";
    //string temp ="jsdvbfg";
    //arg = &temp;
}
void f2_3(const string* const arg){ //const correctness. R->L, Now both pointer and string are const so can't modify
    //*arg="Hello Pointer";
    //string temp ="jsdvbfg";
    //arg = &temp;
}

// void f3_0(string &arg){
//     arg = "hello Reference";
// }
void f3_1(string &arg){ //Read const correctness for reference also
    arg = "hello Reference";
}

int main(){
    string data="hi";
    f1(data);
    cout<<data<<endl;
    f2_3(&data);
    cout<<data<<endl;
    f3_1(data);
    cout<<data<<endl;
    return 0;
}