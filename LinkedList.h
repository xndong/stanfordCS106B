/**
 * A linkedlist is made up of listnode.
 */

#ifndef _linkedlist_h
#define _linkedlist_h

struct ListNode
{
    ListNode(int value = 0, ListNode *pointer = nullptr);
    ~ListNode();
    int data;
    ListNode *next;
};

class LinkedList
{

public:
    //constructor
    LinkedList(ListNode *p = nullptr); //default constructor： non-parameter or have default parameter so can be skiped.
    //destructor
    ~LinkedList();
    int get(int index);
    void set(int index, int value);
    void add(int value);
    void insert(int index, int value);
    void clear();
    bool isEmpty();
    void remove(int value);
    void removeIndex(int index);
    int size() const;
    void traverseLinkedList();

private:
    ListNode *front;
};

void traverseLinkedListFunction(ListNode *front);

#endif