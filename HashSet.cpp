#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include "HashSet.h"
using namespace std;

HashSet::HashSet(int capacity, int mySize)
{
    this->capacity = capacity;
    this->mySize = mySize;
    buckets.resize(capacity, nullptr);
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
    for (int i = 0; i < capacity; i++)
    {
        cout << "[" << setw(2) << i << "]";
        HashNode *curr = buckets[i];
        while (curr != nullptr)
        {
            cout << " -> " << setw(2) << curr->data;
            curr = curr->next;
        }
        cout << " /" << endl;
    }
    cout << "size = " << mySize << endl;
}
void HashSet::remove(int value)
{
    if (!contains(value))
        return;
    int bucket = hashCode(value);
    //remove the first element in chain
    if (buckets[bucket]->data == value)
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
            if (current->next->data == value)
            {
                current->next = current->next->next;
                mySize--;
                return;
            }
            current = current->next;
        }
    }
}
int HashSet::hashCode(int value) const // a naive version hashCode() ---> a hash function.
{
    return abs(value) % capacity;
}
