#include<iostream>
using namespace std;

class Vehicle{
private:
	string regNumber;
	string name;
public:
    void start(){
        cout<<"Key Start"<<endl;
    }
    void stop(){
        cout<<"Key Stop"<<endl; 
    }
    virtual void drive() = 0;
};

class Car:public Vehicle{
public:
    void drive(){
        cout<<"Car Drive"<<endl; //template pattern
    }
};

class Truck:public Vehicle{
public:
    void drive(){
        cout<<"Truck Drive"<<endl; //template pattern
    }
};

class VehicleSimulator{
	Vehicle *v;
public:
VehicleSimulator(Vehicle *vArg):v{vArg}{} //dependency injection
	void start(){ v->start(); } //start and stop will be 
	void stop(){ v->stop(); }   // same for both car and truck
	void drive(){ v->drive(); } //But drive method will be different for car and truck
};

int main(){
	Car vehicle;
	VehicleSimulator simulator(&vehicle);
    simulator.start();
    simulator.drive();
    simulator.stop();
    return 0;
}