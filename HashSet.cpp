#include <vector>
#include <string>
#include <cmath>
#include "HashSet.h"
using namespace std;

HashSet::HashSet(int capacity, int mySize)
{
    capacity = capacity;
    mySize = mySize;
    buckets.resize(capacity);
}
HashSet::~HashSet()
{
}
void HashSet::add(int value)
{
    if (!contains(value))
    {
        int bucket = hashCode(value);
        HashNode *newNode = new HashNode(value);
        newNode->next = buckets[bucket];
        buckets[bucket] = newNode;
        mySize++;
    }
}
void HashSet::clear()
{
}
bool HashSet::contains(int value) const
{
    int bucket = hashCode(value);
    HashNode *current = buckets[bucket];
    while (current != nullptr)
    {
        if (current->data == value)
            return true;
        current = current->next;
    }
    return false;
}
void HashSet::printStructure() const
{
}
void HashSet::remove(int value)
{
    if (!contains(value))
        return;
    int bucket = hashCode(value);
    //remove the first element
    if (buckets[bucket]->data == value)
    {
        buckets[bucket] = buckets[bucket]->next;
    }
    //remove non-first element
    else
    {
        HashNode *current = buckets[bucket];
        while (current != nullptr)
        {
            if (current->data == value)
                current->next = current->next->next;
            current = current->next;
        }
        }
}
int HashSet::hashCode(int value) const // a naive version hashCode() ---> a hash function.
{
    return abs(value) % capacity;
}
