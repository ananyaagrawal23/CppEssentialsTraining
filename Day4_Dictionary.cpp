#include<iostream>
#include<vector>
#include<string>
using namespace std;

template <typename K, typename V> 
class keyValue{
    public:
    K key;
    V value;
};

template <typename K, typename V>
class Dictionary{
    vector<keyValue<K,V>> keyValuePairs;
public:
    void add(K key, V value){
        keyValue<K,V> pair;
        pair.key = key;
        pair.value = value;
        keyValuePairs.push_back(pair); //creating copy so that it is not deleted from stack
    }
     V& operator[](const K& key){
        for(auto& pair : keyValuePairs){
            if(pair.key == key){
                return pair.value;
            }
        }
     }
};

int main()
{
    Dictionary<string, string> strMap;
    strMap.add("BLR", "Bengaluru");
    strMap.add("VNS", "Varanasi");
    string value = strMap["BLR"];
    cout << value << endl;

    Dictionary<string, int> strToIntMap;
    strToIntMap.add("One", 1);
    strToIntMap.add("Two", 2);
    int number = strToIntMap["One"];
    cout << number << endl;

    return 0;
}