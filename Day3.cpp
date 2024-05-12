#include<string>
#include<iostream>
using namespace std;


//Now to remove duplication of data members in printer and scanner we will add one more class called "Device" which printer and scanner will derive.Now we are trapped in DIAMOND PROBLEM. 

class Device{
private:
    string name;
    string model;
    string version;
public:
    Device(){
        cout<<"Device constructor invoked"<<endl;
    }
    ~Device(){
        cout<<"Device destructor invoked"<<endl;
    }
};

class Printer:public Device{
public:
    Printer(){
        cout<<"Printer constructor invoked"<<endl;
    }
    ~Printer(){
        cout<<"Printer destructor invoked"<<endl;
    }
    void print(string content){
        cout<<"Print"<<content<<endl;
    }
};

class Scanner:public Device{
public:
    Scanner(){
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
    PrintScanner(){
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
    PrintScanner hpPrintScanner;
    TaskManager taskMgr;
    //taskMgr.InvokePrintTask(&hpPrinter, "doc.pdf");
    //taskMgr.InvokeScanTask(&hpScanner, "doc.pdf");
    taskMgr.InvokePrintTask(&hpPrintScanner, "doc.pdf");
    taskMgr.InvokeScanTask(&hpPrintScanner, "doc.pdf");
    return 0;
}