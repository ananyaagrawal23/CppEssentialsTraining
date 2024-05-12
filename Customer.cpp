#include<string>
using namespace std;

class Customer {
private:
    string name,address,pan,aadhar,emailId,contactNumber;
public:
    //universal
    //This syntax causes the constructoir to be called with these mandatory arguments so obj can't be created without passing these values
    Customer(string nameArg,
    string addressArg,
    string panArg,
    string aadharArg):name{nameArg}, address{addressArg}, pan{panArg}, aadhar{aadharArg} {
        
    }
    //Functiona overloading. Overloading the above constructor
    Customer(string nameArg,
    string addressArg,
    string panArg,
    string aadharArg,
    string contactNumberArg):name{nameArg}, address{addressArg}, pan{panArg}, aadhar{aadharArg}, contactNumber{contactNumberArg} {
        
    }
    //telescopic constructor chain
    Customer(string nameArg,
    string addressArg,
    string panArg,
    string aadharArg,
    string contactNumberArg,
    string emailIdArg):name{nameArg}, address{addressArg}, pan{panArg}, aadhar{aadharArg}, contactNumber{contactNumberArg}, emailId{emailIdArg} {
        
    }
};

int main()
{
    Customer customerObj1 {"Tom", "BLR", "GSHDJ2343H", "1234567890"};
    Customer customerObj2 {"Tom", "BLR", "GSHDJ2343H", "1234567890", "2846379812"};
    return 0;
}