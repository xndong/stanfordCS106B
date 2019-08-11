#ifndef _heapbinarytree_h
#define _heapbinarytree_h

struct TreeNode
{
    //cosntructor and destructor
    TreeNode(int value = 0, TreeNode *parentPointer = nullptr, TreeNode *leftPointer = nullptr, TreeNode *rightPointer = nullptr);
    ~TreeNode();
    //member varibles
    int data;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
    //member functions
};

class HeapBinaryTree
{
public:
    //constructor and destructor
    HeapBinaryTree(TreeNode *p = nullptr);
    ~HeapBinaryTree();
    //member functions
    bool isEmpty();
    void addHeapBinaryTreeNode(int value); //a.k.a bubble-up
    int topHeapBinaryTreeNode();           //access peek element
    void removeHeapBinaryTreeNode();       //a.k.a bubble-down
    /**
     * Heap最开始我们学的是用vector, array,现在用binarytree,可以推出这种二叉树肯定是满的。
     * bubble-up:
     *    向vector.push_back()    <------->    binarytree最后一个位置添加一个结点
     */
    void levelOrderHeapBinaryTree(TreeNode *root);
    void preOrderHeapBinaryTree(TreeNode *root);
    void inOrderHeapBinaryTree(TreeNode *root);
    TreeNode *rootGetter();

private:
    //member varibles
    TreeNode *root;
};

#endif