#ifndef _hashmap_h
#define _hashmap_h
#include <vector>
#include <string>
using namespace std;
struct HashNode
{
    HashNode(string key = "", int value = 0)
    {
        this->key = key; //重名，所以加this指针?
        this->value = value;
    }
    ~HashNode();
    string key;
    int value;
    HashNode *next;
};
class HashMap
{
public:
    //constructors and destructors
    HashMap(int initcapacity = 10, int initmySize = 0);
    ~HashMap();
    //member functions
    void add(string key, int value);
    bool contains(string key);
    void remove(string key);
    void clear();
    void printStructure();
    float calculateLoadFactor();

private:
    //member varibles
    int capacity;
    int mySize;
    vector<HashNode *> buckets;
    //member functions
    int hashCode(const string &key);
};
#endif