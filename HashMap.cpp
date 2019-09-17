#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include "HashMap.h"

using namespace std;

const int HASH_SEED = 5381;
const int HASH_MULTIPLIER = 33;
const int HASH_MASK = unsigned(-1) >> 1;

HashMap::HashMap(int initcapacity, int initmySize)
{
    capacity = initcapacity; //不需要显式使用this指针： this->capacity = initcapacity
    mySize = initmySize;
    buckets.resize(capacity, nullptr);
}
HashMap::~HashMap()
{
}
void HashMap::add(string key, int value)
{
    if (!contains(key))
    {
        int bucket = hashCode(key);
        HashNode *newNode = new HashNode(key, value);
        newNode->next = buckets[bucket];
        buckets[bucket] = newNode;
        mySize++;
    }
}
bool HashMap::contains(string key)
{
    int bucket = hashCode(key);
    HashNode *current = buckets[bucket];
    while (current != nullptr)
    {
        if (current->key == key)
            return true;
        current = current->next;
    }
    return false;
}
void HashMap::printStructure()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << "[" << setw(2) << i << "]";
        HashNode *curr = buckets[i];
        while (curr != nullptr)
        {
            cout << " -> " << setw(2) << "(" << curr->key << "," << curr->value << ")";
            curr = curr->next;
        }
        cout << " /" << endl;
    }
    cout << "size = " << mySize << endl;
}
void HashMap::remove(string key)
{
    if (!contains(key))
        return;
    int bucket = hashCode(key);
    //remove the first element in chain
    if (buckets[bucket]->key == key)
    {
        buckets[bucket] = buckets[bucket]->next;
        mySize--;
    }
    //remove non-first element in chain
    else
    {
        HashNode *current = buckets[bucket];
        while (current->next != nullptr)
        {
            if (current->next->key == key)
            {
                current->next = current->next->next;
                mySize--;
                return;
            }
            current = current->next;
        }
    }
}
void HashMap::clear()
{
}
float HashMap::calculateLoadFactor()
{
    int count = 0;
    for (auto p : buckets)
    {
        if (p != nullptr)
            count++;
    }
    float load_factor = float(count) / capacity;
    if (load_factor < 0.75)
        cout << "Currently, hash table's load factor is: " << load_factor << ", still safe." << endl;
    else
    {
        cout << "Currently, hash table's load factor is: " << load_factor << ", you are encouraged to re-hash." << endl;
    }
    return load_factor;
}
int HashMap::hashCode(const string &key)
{
    unsigned hash = HASH_SEED;
    int n = key.length();
    for (char c : key)
        hash = HASH_MULTIPLIER * hash + c;
    return (int(hash & HASH_MASK) % capacity);
}