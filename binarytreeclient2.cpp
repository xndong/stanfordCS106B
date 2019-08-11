#include <iostream>
#include <string>
#include "BinaryTree.h"

using namespace std;

void preOrderTraverse(TreeNode *node);
void preOrderTraverse2(TreeNode *node);

int main()
{
    TreeNode *root = new TreeNode(49);
    BinaryTree binarySearchTree(root);
    binarySearchTree.addBinarySearchTreeNode(25);
    binarySearchTree.addBinarySearchTreeNode(160);
    binarySearchTree.addBinarySearchTreeNode(21);
    binarySearchTree.addBinarySearchTreeNode(36);
    binarySearchTree.addBinarySearchTreeNode(81);
    binarySearchTree.addBinarySearchTreeNode(196);
    binarySearchTree.addBinarySearchTreeNode(3);
    binarySearchTree.addBinarySearchTreeNode(23);
    binarySearchTree.addBinarySearchTreeNode(200);
    binarySearchTree.addBinarySearchTreeNode(1);
    /**
     *we can get such a binary search tree
     *                    49
     * 
     *             25          160
     *         
     *          21     36   81      196
     * 
     *        3   23                      200
     * 
     *      1
     */
    preOrderTraverse(root);
    cout << endl;
    /**
     * 这里的root是第一行declare的root,也是它把自己assign给了BinaryTree里的private member variable root.
     * 这里的root并不是类里那个root因为类里那个是属于对象的，而且是private的
     * 但是因为它assign value给BinaryTree里的root,所以都指向 new TreeNode(49) 返回的地址，也就是我们design的树的root。
     * 这里的陷阱和之前LinkedList里linkedlistclient.cpp一样。
     * */

    // another add ----> using recursive
    BinaryTree binarySearchTree2;
    binarySearchTree2.addBinarySearchTreeNode2(49);
    binarySearchTree2.addBinarySearchTreeNode2(25);
    binarySearchTree2.addBinarySearchTreeNode2(160);
    binarySearchTree2.addBinarySearchTreeNode2(21);
    binarySearchTree2.addBinarySearchTreeNode2(36);
    binarySearchTree2.addBinarySearchTreeNode2(81);
    binarySearchTree2.addBinarySearchTreeNode2(196);
    binarySearchTree2.addBinarySearchTreeNode2(3);
    binarySearchTree2.addBinarySearchTreeNode2(23);
    binarySearchTree2.addBinarySearchTreeNode2(200);
    binarySearchTree2.addBinarySearchTreeNode2(1);
    binarySearchTree2.print(); //preorder traverse
    cout << endl;

    //create from vector
    TreeNode *p = nullptr;
    BinaryTree bst;
    vector<int> vec{49, 25, 160, 21, 36, 81, 196, 3, 23, 200, 1};
    p = bst.createBinarySearchTree(vec);
    preOrderTraverse(p);
    cout << endl;
    /**
     * p ---->  pointee
     * another_p = p
     * another_p ----> pointee
     * when
     * anoter_p -----> another pointee
     * of course, p won't be changed and p ----> pointee, but you need to be careful because it's easy to forget and then fall off!
     */

    cout << boolalpha << bst.isInBinarySearchTree(49) << endl;
    cout << boolalpha << bst.isInBinarySearchTree(81) << endl;
    cout << boolalpha << bst.isInBinarySearchTree(1) << endl;
    cout << boolalpha << bst.isInBinarySearchTree(100) << endl;
    cout << boolalpha << bst.isInBinarySearchTree2(49) << endl;
    cout << boolalpha << bst.isInBinarySearchTree2(81) << endl;
    cout << boolalpha << bst.isInBinarySearchTree2(1) << endl;
    cout << boolalpha << bst.isInBinarySearchTree2(100) << endl;

    bst.deleteBinarySearchTreeNode(1024);
    bst.deleteBinarySearchTreeNode(49);
    bst.deleteBinarySearchTreeNode(21);
    bst.deleteBinarySearchTreeNode(3);
    bst.deleteBinarySearchTreeNode(1);
    preOrderTraverse(p);

    return 0;
}

void preOrderTraverse(TreeNode *node)
{
    cout << node->data << ", ";
    if (node->left != nullptr)
        preOrderTraverse(node->left);
    if (node->right != nullptr)
        preOrderTraverse(node->right);
}
void preOrderTraverse2(TreeNode *node)
{
    if (node != nullptr)
    {
        cout << node->data << ", ";
        preOrderTraverse(node->left);
        preOrderTraverse(node->right);
    }
}