#include<iostream>
#include<string>
using namespace std;

class MediaItem {
private:
    string name;
    string dateCreated;
    int size;
public:
    MediaItem(string nameArg, string dateArg, int sizeArg)
    {
        this->name = nameArg;
        this->dateCreated = dateArg;
        this->size = sizeArg;
    }
};

class Image:public MediaItem {
private:
    string name;
    string dateCreated;
    int size;
public:
    
};

class Video:public MediaItem {

};

class Gallary {

};

int main()
{
    return 0;
}