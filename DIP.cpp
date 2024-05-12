// Car uses/depends on Engine (dependency comes in->Has-a)

//Abstraction
class IEngine {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
};

//Low level module -> Offers the service
class MPFIEngine:public IEngine{
public:
    void start();
    void stop();
};

class GDIEngine:public IEngine {
public:
    void start();
    void stop();
};

class StallinEngine:public IEngine {
public:
    void start();
    void stop();
};

//High level module -> Uses the service
class XUV3X0 {
    //MPFIEngine engine; //Tightly coupled when abstraction was not there
    //Dependency (abstract)
    IEngine* engine; //Loosely coupled
public:
//Constructor dependency injection
    XUV3X0(IEngine* engineArg):engine{engineArg}{} //using universal initializer
    void drive(){
        this->engine->start();
    }
    void halt(){
        this->engine->stop();
    }
    ~XUV3X0(){
        delete engine; //Death relationship: when container removed, delete all contained objects
    }
};

int main()
{
    MPFIEngine napEngine;
    GDIEngine turboEngine;
    XUV3X0 car{&napEngine}; //Base class ptr now pointing to adress of derived class
    car.drive();
    XUV3X0 turboCar{&turboEngine};
    return 0;
}
