#include <iostream>
#include "linkedlist.h"

using namespace std;

int main()
{
    //测试(单向)linkedlist的所有的member function
    //ListNode *front = new ListNode(1);
    //LinkedList myLinkedList(front);
    LinkedList myLinkedList; //stack allocation没有参数时不需要空括号！！！动态分配使用new时，没有参数也要有空括号
    myLinkedList.add(1);
    myLinkedList.add(3);
    myLinkedList.add(5);
    myLinkedList.add(7);
    myLinkedList.traverseLinkedList();
    cout << myLinkedList.get(3) << endl;
    cout << myLinkedList.size() << endl;
    myLinkedList.set(3, 100);
    myLinkedList.add(1000);
    myLinkedList.add(1000);
    myLinkedList.add(1000);
    myLinkedList.traverseLinkedList();
    myLinkedList.insert(3, 10);
    myLinkedList.traverseLinkedList();
    myLinkedList.remove(10);
    myLinkedList.traverseLinkedList();

    myLinkedList.removeIndex(0);
    myLinkedList.traverseLinkedList();
    myLinkedList.removeIndex(1);
    myLinkedList.traverseLinkedList();
    myLinkedList.removeIndex(4);
    myLinkedList.traverseLinkedList();

    cout << myLinkedList.size() << endl;
    cout << myLinkedList.isEmpty() << endl;

    myLinkedList.clear();
    cout << myLinkedList.size() << endl;
    cout << myLinkedList.isEmpty() << endl;
    myLinkedList.removeIndex(0);
    myLinkedList.traverseLinkedList();

    return 0;
}