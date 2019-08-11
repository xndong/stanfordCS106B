#include <iostream>
#include "listnode.h"

using namespace std;

int main()
{
    ListNode *node0 = new ListNode();
    ListNode *node1 = new ListNode(1); //'new' will return an address
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    //glue,chain,link them together
    node0->next = node1; // For a pointer : ->  equals to *().
    node1->next = node2; //两个指针之间赋值，它们将point to the same staff i.e. they have the same pointee when derefernce
    node2->next = node3;
    node3->next = node4;
    cout << node0->value << endl;
    cout << node1->value << endl;
    cout << node2->value << endl;
    cout << node3->value << endl;
    cout << node4->value << endl;
    //We always define a node type pointer as above.
    //---------------------------------------------------------------------------------------------------------------
    //We define a node less common as follows.
    ListNode nodex = *(new ListNode()); //'new' return的是node的memory address,这个地址指向该node。所以需要用 * 来取node。
    ListNode nodey = *(new ListNode(10));
    ListNode nodez = *(new ListNode(100));
    nodex.next = &nodey;
    nodey.next = &nodez;
    cout << nodex.value << endl;
    cout << nodey.value << endl;
    cout << nodez.value << endl;
    /**
     * C++ structure vs C structure
     * Both use keywords 'struct'. 
     * However, C++ structure is a holdover from C and it has some new features.
     * C++ structure is class. To be more specific, it only has public memeber varibles and has no member functions(but it can have).(Thus, 'public' and 'private' keywords can be saved.)
     * Of courese, you can use keywords 'class' instead of 'struct', but to comply with the convention, we prefer to use keywords 'struct'
     * ----------------------------------------------------------------------------------------------------------------------------------
     * In C++, we use keywords 'new' to achieve memory 'dynamic allocation' (a.k.a. 'heap allocation').
     * Syntax: 
     *      = new int;                                                                             int a=10;
     *      =new int[10] new int[n];                                  vs stack allocaton           int array[10]={1,2,3,4,5,6,7,8,9,0}
     *      =new classname(parmeters, if applicable);                                              int classname(parameters,if applicable)    //basically, parameters depend on constructors
     *      =new classname()                                                                       int classname                              //if constructor has no parameter, stack allocation don't need () after classname!!!
     * Features about heap allocation: 
     *      using keyword 'new' to allocate memory, new int开辟一块int类型大小的memory用来存放int类型的变量；new int[10]开辟一块能放10个int大小的memory来存放int类型的数组变量...
     *      using corresponding type of pointer to point to the allocated memory 
     *      self memory management ,so must be delete[] in case of memory leak
     */
    ListNode *myNode = new ListNode();
    ListNode *startNode = createLinkedList(myNode, 20);

    ListNode *current = startNode;
    for (int i = 0; current != nullptr; i++)
    {
        cout << "Node " << i << "'s value: " << current->value << endl;
        current = current->next;
    }

    traverseLinkedList(startNode);

    return 0;
}

/**
 * int * pt = nullptr;
 * int * p = &a;
 * pointer : p
 * pointee : *p or a
 * 
 * pt = p; // 指针之间赋值：pt and p will point to the same staff, they have the same pointee —— p's pointee.
 */

/**
 * Don't fall off the edge : while(current->next != nullptr)
 * 任何时候、任何修改都要检查最后一个node的next域是否设为nullptr,这样才有edge。
 * -> can only be used by a pointer! equals to *().
 */