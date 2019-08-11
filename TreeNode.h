#ifndef _treenode_h
#define _treenode_h

using namespace std;

struct TreeNode
{
    //construtor and destructor
    TreeNode(int dataValue = 0, TreeNode *leftPointer = nullptr, TreeNode *rightPointer = nullptr);
    ~TreeNode();

    //member functions
    bool isLeaf();

    //memeber varibles
    int data;
    TreeNode *left;
    TreeNode *right;
};

#endif