#include <iostream>
#include <vector>
#include <string>
#include "stringmap.h"
using namespace std;

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
    if (index == -1)
    {
        KeyValuePair entry;
        entry.key = key;
        index = bindings.size();
        bindings.push_back(entry);
    }
    bindings.at(index).value = value;
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