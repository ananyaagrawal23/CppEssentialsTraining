//Interface
//Contract
class IEmployee {
public:
    virtual void professional() = 0; //Pure virtual function
};

class IFamilyMember {
public:
    virtual void casual() = 0; //Pure virtual function
    virtual void cranky() = 0;
};

class Person:public IEmployee, public IFamilyMember{ //Person fulfills IEmployee contract (implements in Java)
    // Default interface of the object
public:
	void casual(){}
	void professional(){}
    void cranky(){}
};

class OfficeContext{
public:
    void Enter(IEmployee* obj){
        //obj->cranky(); //this should throw error in this context when we created Person * obj, now it gives error after giving ptr to IEmployee
        //obj->casual(); 
        obj->professional();
    }
};

class FamilyContext{
public:
    void Enter(IFamilyMember* obj){
        obj->cranky(); 
        obj->casual();
        //obj->professional(); 
    } 
};

int main(){
    //Concept of interface and abstraction in Cpp
    Person tom;
    FamilyContext fContext;
    OfficeContext oContext;
    fContext.Enter(&tom);
    oContext.Enter(&tom);

    //Changing obj of class but ptr remains same 
    Person harry;
    fContext.Enter(&harry);
    oContext.Enter(&harry);
    return 0;
}