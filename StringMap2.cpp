#include <iostream>
#include <vector>
#include <string>
#include "stringmap2.h"
using namespace std;

KeyValuePair::KeyValuePair(string initKey, string initValue)
{
    key = initKey;
    value = initValue;
}
KeyValuePair::~KeyValuePair()
{
}

StringMap::StringMap()
{
}
StringMap::~StringMap()
{
}
string StringMap::get(const string &key) const
{
    int index = findKey(key);
    return (index == -1) ? "" : bindings.at(index).value;
}
void StringMap::put(const string &key, const string &value)
{
    int index = findKey(key);
    if (index != -1)
        bindings.at(index).value = value;
    else
    {
        KeyValuePair entry(key, value);
        bindings.push_back(entry);
    }
}
int StringMap::findKey(const string &key) const
{
    for (int i = 0; i < bindings.size(); i++)
    {
        if (bindings.at(i).key == key) //bindings[i].key
            return i;
    }
    return -1;
}