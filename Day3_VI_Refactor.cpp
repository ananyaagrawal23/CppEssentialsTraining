#include<string>
#include<iostream>
using namespace std;


class IPrinter{
public:
    virtual void print() = 0;
};

class Iscanner{
public:
    virtual void scan() = 0;
};

class Device:public IPrinter, public Iscanner{
private:
    string name;
    string model;
    string version;
protected:
//Made this class abstract so this class can be reused but not instantiated
    Device(string nameArg, string modelArg, string versionArg):name{nameArg}, model{modelArg}, version{versionArg}
    {
        cout<<"Device constructor invoked"<<endl;
    }
    ~Device(){
        cout<<"Device destructor invoked"<<endl;
    }
public:
    void print(){}
    void scan(){}
};

class Printer:virtual public Device{
public:
    Printer():Device{"","",""}{
        cout<<"Printer constructor invoked"<<endl;
    }
    ~Printer(){
        cout<<"Printer destructor invoked"<<endl;
    }
    void printTask(IPrinter* obj){
        obj->print();
    }
};

class Scanner:virtual public Device{
public:
    Scanner():Device{"","",""}{
        cout<<"Scanner constructor invoked"<<endl;
    }
    ~Scanner(){
        cout<<"Scanner destructor invoked"<<endl;
    }
    void scanTask(Iscanner* obj){
        obj->scan();
    }
};

class PrintScanner:virtual public Device{ 
    Printer printerObj;
    Scanner scannerObj;
public:
    void printTask(IPrinter* obj){
        obj->print();
    }
    void scanTask(Iscanner* obj){
        obj->scan();
    }
    PrintScanner(string n, string m, string v):Device{n,m,v}{
        cout<<"PrintScanner constructor invoked"<<endl;
    }
    ~PrintScanner(){
        cout<<"PrintScanner destructor invoked"<<endl;
    }
};

class TaskManager{
public:
    void InvokePrintTask(IPrinter* obj){
        obj->print();
    }
    void InvokeScanTask(Iscanner* obj){
        obj->scan();
    }
};

int main(){
    //Printer hpPrinter;
    //Scanner hpScanner;
    PrintScanner hpPrintScanner("","","");
    TaskManager taskMgr;
    //taskMgr.InvokePrintTask(&hpPrinter);
    //taskMgr.InvokeScanTask(&hpScanner);
    taskMgr.InvokePrintTask(&hpPrintScanner);
    taskMgr.InvokeScanTask(&hpPrintScanner);
    return 0;
}

//This code refactor is not correct