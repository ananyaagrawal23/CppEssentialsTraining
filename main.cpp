#include<iostream>
#include <string>

using namespace std;

class LocationModel {
private:
    string name;
    float coOrdinate;
    //static int objCounter; //This is not a state of object
public:
    static void dumpCounter() {
        //Don't want to call "this", with 'this' we need to create object. So we add static
    }
    string getName() { // string getName(LocationModel *this)
        return this->name;
    }
    void setName(string value) { //void setName(LocationModel *this, string value)
        name = value;
    }
};

class Converter{
public:
    void Convert(string filePath){
        //Logic
        //Read CSV file line by line
        //Split each line by ","
        //Represent line content
        //Validate line
        //Create XML node
        //Update XML tree
        //Save XML tree
    }
};

int main()
{
    //Stack objects
    LocationModel obj;
    obj.setName("BLR"); //LocationModel::setName(&obj, "BLR")
    string name = obj.getName();
    cout << name << endl;
    //Heap allocation
    LocationModel *ptr = new LocationModel();
    ptr->setName("DEL");
    name = ptr->getName();
    cout << name << endl;
    return 0;
}