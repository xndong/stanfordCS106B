#ifndef _stringmap_h
#define _stringmap_h
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//class StringMap
class StringMap
{
public:
    //constructor and destructor
    StringMap();
    ~StringMap();
    // member functions
    string get(const string &key) const;              //get
    void put(const string &key, const string &value); //update or add

private:
    struct KeyValuePair //define KV pair type here. of course we can define it outside the class.
    {
        string key;
        string value;
    };
    vector<KeyValuePair> bindings; //use this pair type as basic element in StringMap.
    int findKey(const string &key) const;
};
#endif