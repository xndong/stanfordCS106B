#include <iostream>
#include "listnode.h"

ListNode::ListNode(int initialValue, ListNode *n)
{
    value = initialValue;
    next = n;
}
ListNode::~ListNode()
{
}

ListNode *createLinkedList(ListNode *aNode, int listNodeLength) //new一个node,然后glue together.
{
    ListNode *startPointer = aNode;
    ListNode *p = startPointer;
    for (int i = 0; i < listNodeLength; i++)
    {
        ListNode *tmpNode = new ListNode();
        p->next = tmpNode;
        p = tmpNode;
    }
    p->next = nullptr; //用于顺序访问的loop终止条件
    return startPointer;
}

void traverseLinkedList(ListNode *current)
{
    for (int i = 0; current != nullptr; i++)
    {
        cout << "Node " << i << "'s value: " << current->value << endl;
        current = current->next;
    }
}

bool find(ListNode aNode)
{
}
