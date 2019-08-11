#ifndef _binarytree_h
#define _binarytree_h

#include <string>
#include <vector>

using namespace std;

struct TreeNode
{
    //constructors and destructor
    TreeNode(int dataValue = 0, TreeNode *leftPointer = nullptr, TreeNode *rightPointer = nullptr);
    ~TreeNode();
    //member functions
    bool isLeaf();
    //member varibles
    int data;
    TreeNode *left;
    TreeNode *right;
};

class BinaryTree
{
public: // public之外都默认为private。constructor 和 destructor 要放在public！！！
    //construtors and destructors
    BinaryTree(TreeNode *p = nullptr);
    ~BinaryTree(); //To do

    //member functions
    void print();
    /**
     * 声明的时候可以只写类型，但是定义的时候肯定要写形参
     * contains is a naive traverse searching method(遍历搜索)
     * 二叉搜索树的复杂度更低
     */
    bool contains(int); // a naive traverse searching method. Brutal search：backtracking, traverse(CS106B) etc.
    void printSideways();
    void addBinarySearchTreeNode(int value);
    void addBinarySearchTreeNode2(int value);
    TreeNode *createBinarySearchTree(vector<int> &vec);
    bool isInBinarySearchTree(int value);  //a.k.a contains. we can recursively implement as before(contains) or not recursively
    bool isInBinarySearchTree2(int value); //we use root, node/current just as front, current in LinkedList. i.e. we use loop to walk, shift instead of recursive.
    void deleteBinarySearchTreeNode(int value);
    void remove(int value); // To do, 和delete一样，使用递归实现。
    int getMin();           //To do

private:
    //member varibles
    TreeNode *root;
    //member functions
    void preOrderPrintHelper(TreeNode *node);
    void preOrderPrintHelper2(TreeNode *node);
    bool containsHelper(TreeNode *node, int value);

    //void printSidewaysHelper(TreeNode *node = root, string indent = ""); //private 不能访问 private？
    void printSidewaysHelper(TreeNode *node, string indent);
    void printSidewaysHelper2(TreeNode *node, string indent);
    void addBinarySearchTreeNode2Helper(TreeNode *node, int value);
    bool isInBinarySearchTreeHelper(TreeNode *node, int value);
    TreeNode *isInPosition(TreeNode *node, int value);
    TreeNode *isInParentPosition(TreeNode *node, int value);
    TreeNode *leftSecondMostLeaf(TreeNode *node);
    TreeNode *rightMostLeaf(TreeNode *node);
    int getMinHelper(); //To do
};

#endif