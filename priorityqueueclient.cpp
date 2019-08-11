#include <iostream>
#include "PriorityQueue.h"
#include <vector>

using namespace std;

int main()
{
    vector<int> pqVec{78, 23, 4, 8, 12, 9, 2, 6, 36, 81, 3, 18, 24};

    PriorityQueue pq;
    pq.enqueue(12);
    pq.enqueue(8);
    pq.enqueue(35);
    pq.enqueue(9);
    pq.enqueue(2);
    pq.enqueue(56);
    pq.enqueue(18);
    pq.enqueue(4);
    pq.printRawPQ();
    cout << pq.dequeue() << endl;
    cout << pq.dequeue() << endl;
    cout << pq.dequeue() << endl;
    cout << pq.dequeue() << endl;
    cout << pq.dequeue() << endl;
    cout << pq.dequeue() << endl;
    cout << pq.dequeue() << endl;
    cout << pq.dequeue() << endl;

    PriorityQueue pqTwo(pqVec);
    pqTwo.printRawPQ();
    cout << pqTwo.peek() << endl;
    pqTwo.enqueue(1);
    pqTwo.enqueue(100);
    pqTwo.printRawPQ();
    cout << pqTwo.dequeue() << endl;
    cout << pqTwo.dequeue() << endl;
    pqTwo.printRawPQ();
    pqTwo.printOrderedPQ(); //因为在不断的dequeue,最终会exhaust优先级队列.
    pqTwo.printOrderedPQ();

    return 0;
}