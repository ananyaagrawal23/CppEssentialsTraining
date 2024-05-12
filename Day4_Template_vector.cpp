#include<iostream>
using namespace std;

class IntVector{
    int *items; // Dynamic array to store elements
    int size; // Current size of the array
    int capacity; // Capacity of the array

public:
    IntVector(){
        capacity = 3; // Initial capacity
        size = 0; // No elements initially
        items = new int[capacity]; // Allocate memory for initial capacity
    }

    ~IntVector(){
        delete[] items; // Destructor to free dynamically allocated memory
    }

    void push_back(int item){
        if(size < capacity){
            items[size++] = item; // Add item and increment size
        }
        else{
            // If capacity is reached, double the capacity
            capacity *= 2;
            int *temp = new int[capacity]; // Allocate memory for the new capacity
            for(int i = 0; i < size; i++){
                temp[i] = items[i]; // Copy elements to the new array
            }
            delete[] items; // Free memory of the old array
            items = temp; // Update pointer to the new array
            items[size++] = item; // Add the new item and increment size
        }
    }

    int operator[](int index) const{
        if(index < 0 || index >= size){
            cout << "Index out of range." << endl;
            return -1; // You may want to handle this differently based on your requirements
        }
        return items[index];
    }
};

int main(){
    IntVector v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    int item = v[4];
    cout<<item<<endl;
    return 0;
}
