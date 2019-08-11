#include <iostream>
#include "HeapBinaryTree.h"

using namespace std;

int main()
{
    HeapBinaryTree heap;
    heap.addHeapBinaryTreeNode(15);
    heap.addHeapBinaryTreeNode(26);
    heap.addHeapBinaryTreeNode(9);
    heap.addHeapBinaryTreeNode(67);
    heap.addHeapBinaryTreeNode(65);
    heap.addHeapBinaryTreeNode(5);
    heap.addHeapBinaryTreeNode(48);
    heap.addHeapBinaryTreeNode(21);
    heap.addHeapBinaryTreeNode(19);
    TreeNode *root = heap.rootGetter();
    heap.levelOrderHeapBinaryTree(root);
    // while (!heap.isEmpty())
    // {
    //     cout << heap.topHeapBinaryTreeNode() << ", ";
    //     heap.removeHeapBinaryTreeNode();
    // }
    return 0;
}