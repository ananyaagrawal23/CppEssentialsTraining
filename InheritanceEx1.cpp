#include<iostream>
#include<string>
using namespace std;

class Laptop { // Class Laptop is NOT concrete, it does not make sense to make object of just Laptop class, so we need to stop making object of laptop class. Laptop class is only for code reuseability. So we use concept of PROTECTED CONSTRUCTOR. (Check ONENOTE)

protected:
    Laptop() {
        
    }
private:
    string modelName;
    string serialNumber;
    string color;
    float weight;
    string hostOsType;
    int storageCapacity;
};

//Compile-time relationship OR Static relationship
class HPLaptop:public Laptop { // HPLaptop IS A Specialized Laptop
private:

};

class ZeLaptop {
    
};

class LenovoLaptop {
    
};

int main() {
    return 0;
}