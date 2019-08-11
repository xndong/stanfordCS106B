#ifndef _listnode_h
#define _listnode_h

using namespace std; //  Fuck you namespace!

struct ListNode
{
    ListNode(int initialValue = 0, ListNode *n = nullptr);
    ~ListNode();
    int value;
    ListNode *next; //next并不是一个node。i.e. 并不是里面还有一个node，而是存放的另一个node的地址。因此，可以把多个node glue起来/粘起来
};

ListNode *createLinkedList(ListNode *aNode, int listNodeLength);
void traverseLinkedList(ListNode *p);
bool find(ListNode aNode);

#endif