#include<iostream>
using namespace std;

class BankAcc{
    int balance;
    public:
    BankAcc(int initBal):balance(initBal){}
    int getBal()const {return this->balance;}
    //const BankAcc* const this
    BankAcc operator+(const BankAcc& operandTwo) const {
        BankAcc newAcc{0};
        newAcc.balance = this -> getBal() + operandTwo.balance;
        return newAcc;
    }
};

int main(){
    BankAcc acc1{1000};
    BankAcc acc2{2000};
    cout<<acc1.getBal()<<endl;
    cout<<acc2.getBal()<<endl;
    BankAcc acc3 = acc1+acc2;
    cout<<acc3.getBal()<<endl;
    return 0;
}