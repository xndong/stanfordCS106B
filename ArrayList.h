#ifndef _ArrayList_h
#define _ArrayList_h

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class ArrayList
{
public:
    //constructor
    ArrayList();
    ~ArrayList();
    //member functions
    void add(int value);
    void clear();
    int get(int index) const;
    void insert(int index, int value);
    bool isEmpty() const;
    void remove(int index);
    void set(int index, int value);
    int size() const;
    int capacity() const;
    void debug() const;

private:
    //member varibles or instance varibles
    int *myElements;
    int mySize;
    int myCapacity;

    void checkIfResize();
};

//overloaded operators

ostream &operator<<(ostream &out, ArrayList &list);

#endif