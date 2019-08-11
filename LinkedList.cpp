#include <iostream>
#include "linkedlist.h"

using namespace std;

ListNode::ListNode(int value, ListNode *pointer)
{
    data = value;
    next = pointer;
    cout << "ListNode constructor is called." << endl;
}
ListNode::~ListNode()
{
    cout << "ListNode destructor is called." << endl;
}

LinkedList::LinkedList(ListNode *p) //constructor:为 member variable assign or initialize values
{
    front = p;
    cout << "LinkedList constructor is called." << endl;
}
LinkedList::~LinkedList()
{
    cout << "LinkedList destructor is called." << endl;
    clear();
}
int LinkedList::get(int index)
{
    if (front == nullptr)
        return -1;

    ListNode *current = front;
    if (index == 0)
        return current->data;
    //we are using loop to shift our pointer 'current'. i.e. walk to the position we want.
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data;
}
void LinkedList::set(int index, int value)
{
    if (front == nullptr)
        return;

    ListNode *current = front;
    //we are using loop to shift our pointer 'current'.
    for (int i = 0; i < index; i++)
    {
        //current和current->next指向相同的东西。Specifically,我们把current赋值成current->next指向的地址，此时二者便指向相同的东西了
        current = current->next;
    }
    current->data = value;
}
void LinkedList::add(int value)
{
    ListNode *back = new ListNode(value, nullptr);
    if (front == nullptr)
    {
        front = back;
    }
    else
    {
        ListNode *current = front;
        // shift the pointer 'current' to walk to the end
        while (current->next != nullptr)
        {
            current = current->next;
        }
        //glue new node here
        current->next = back;
    }
}
void LinkedList::insert(int index, int value)
{
    if (index == 0)
    {
        ListNode *oldfront = front;
        ListNode *front = new ListNode(value);
        front->next = oldfront;
    }
    else
    {
        ListNode *insertNode = new ListNode(value);
        ListNode *current = front;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        ListNode *tmp = current->next;
        current->next = insertNode;
        insertNode->next = tmp;
    }
}
void LinkedList::clear()
{
    //front = nullptr; //memory leakage
    while (front != nullptr)
    {
        removeIndex(0);
    }
}
bool LinkedList::isEmpty()
{
    if (front == nullptr)
        return true;
    return false;
}
void LinkedList::remove(int value)
{
    ListNode *trash = nullptr;
    ListNode *current = front;
    if (current->data == value)
    {
        trash = front;
        front = front->next;
    }
    else
    {
        while (current->next->data != value) //让current指向targeted node(value not index, index is easy, just '< index-1' )的前一个node的表示方法！！！
        {
            current = current->next;
        }
        trash = current->next;
        current->next = current->next->next;
    }

    delete trash; //之前new出来的东西现在要remove掉，所以要delete以防memory leakage
}

void LinkedList::removeIndex(int index)
{
    ListNode *trash;
    ListNode *current = front;
    if (front == nullptr)
    {
        cout << "This is an empty linkedlist and remove by index is invalid." << endl;
        return;
    }
    if (index == 0)
    {
        if (current->next == nullptr)
        {
            trash = front;
            front = nullptr;
        }
        else
        {
            trash = front;
            front = front->next;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        trash = current->next;
        current->next = current->next->next;
    }
    delete trash;
}
int LinkedList::size() const
{
    if (front == nullptr)
        return 0;
    int size = 1;
    ListNode *current = front;
    while (current->next != nullptr)
    {
        size++;
        current = current->next;
    }
    return size;
}
void LinkedList::traverseLinkedList()
{
    if (front == nullptr)
    {
        cout << "This is an empty linkedlist and traverse is invalid." << endl;
        return;
    }
    ListNode *current = front;
    while (true)
    {
        //do something e.g. print
        cout << current->data << " ";
        if (current->next == nullptr)
            break;
        current = current->next;
    }
    cout << endl;
}
void traverseLinkedListFunction(ListNode *front)
{
    if (front == nullptr)
    {
        cout << "This is an empty linkedlist and traverse is invalid." << endl;
        return;
    }
    ListNode *current = front;
    while (true)
    {
        //do something e.g. print
        cout << current->data << " ";
        if (current->next == nullptr)
            break;
        current = current->next;
    }
    cout << endl;
}
