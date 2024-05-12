#include<string>
#include<iostream>
using namespace std;


//Now to remove duplication of data members in printer and scanner we will add one more class called "Device" which printer and scanner will derive.Now we are trapped in DIAMOND PROBLEM. To solve that we added virtual keyword in this case

class Device{
private:
    string name;
    string model;
    string version;
public:
//Now since data members are private, we made parameterized constructor, but now eorror will be thrown as compiler looks for default constructor in inheritance.SO we call device constructor directly from grandcjhild printscanner which is the violation of inheritance rules
    Device(string nameArg, string modelArg, string versionArg):name{nameArg}, model{modelArg}, version{versionArg}
    {
        cout<<"Device constructor invoked"<<endl;
    }
    ~Device(){
        cout<<"Device destructor invoked"<<endl;
    }
};

class Printer:virtual public Device{
public:
    Printer():Device{"","",""}{
        cout<<"Printer constructor invoked"<<endl;
    }
    ~Printer(){
        cout<<"Printer destructor invoked"<<endl;
    }
    void print(string content){
        cout<<"Print"<<content<<endl;
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
    void scan(string content){
        cout<<"Scan"<<content<<endl;
    }
};

class PrintScanner:public Printer,public Scanner{ //Multiple inheritance, don't use this
public:
    PrintScanner(string n, string m, string v):Device{n,m,v}{
        cout<<"PrintScanner constructor invoked"<<endl;
    }
    ~PrintScanner(){
        cout<<"PrintScanner destructor invoked"<<endl;
    }
};

class TaskManager{
public:
    void InvokePrintTask(Printer *printerPtr, string content){
        printerPtr->print(content);
    }
    void InvokeScanTask(Scanner *scannerPtr, string content){
        scannerPtr->scan(content);
    }
};

int main(){
    //Printer hpPrinter;
    //Scanner hpScanner;
    PrintScanner hpPrintScanner("","","");
    TaskManager taskMgr;
    //taskMgr.InvokePrintTask(&hpPrinter, "doc.pdf");
    //taskMgr.InvokeScanTask(&hpScanner, "doc.pdf");
    taskMgr.InvokePrintTask(&hpPrintScanner, "doc.pdf");
    taskMgr.InvokeScanTask(&hpPrintScanner, "doc.pdf");
    return 0;
}

//This code is very bad, multiple inheritance shuldn't be used. The refactoring of this code without using multiple inheritance is in file "Day3_VI_Refactor.cpp"