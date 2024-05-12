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

    //Delegating optional arguments to another class//builder pattern
    void setContactNumber(string contactNumberArg) {
        this->contactNumber = contactNumberArg;
    }

    void setEmailId(string emailIdArg) {
        this->emailId = emailIdArg;
    }
    
};

class CustomerBuilder {
public:
    CustomerBuilder(string name, string adress, string pan, string aadhar) {
        
    }    
};

int main()
{
    Customer customerObj1 {"Tom", "BLR", "GSHDJ2343H", "1234567890"};
    Customer customerObj2 {"Tom", "BLR", "GSHDJ2343H", "1234567890", "2846379812"};
    return 0;
}