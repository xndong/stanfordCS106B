#ifndef _stringmap2_h
#define _stringmap2_h
#include <iostream>
#include <vector>
#include <string>
using namespace std;
/**
 * I think my design and solution is better than standford's.
*/

//basic element in stringmap
struct KeyValuePair
{
    KeyValuePair(string initKey = "", string initValue = "");
    ~KeyValuePair();
    string key;
    string value;
};
//class StringMap
class StringMap
{
public:
    //constructor and destructor
    StringMap();
    ~StringMap();
    // member functions
    string get(const string &key) const;              // get
    void put(const string &key, const string &value); // update or add

private:
    // member varible
    vector<KeyValuePair> bindings;
    // private member functions
    int findKey(const string &key) const;
};
#endif