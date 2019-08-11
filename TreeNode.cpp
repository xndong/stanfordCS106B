#include "TreeNode.h"

using namespace std;

TreeNode::TreeNode(int dataValue, TreeNode *leftPointer, TreeNode *rightPointer)
{
    data = dataValue;
    left = leftPointer;
    right = rightPointer;
}

TreeNode::~TreeNode()
{
}

bool TreeNode::isLeaf()
{
    if (left == nullptr && right == nullptr)
        return true;
    return false;
}