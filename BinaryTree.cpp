#include <iostream>
#include <string>
#include "BinaryTree.h"

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
    return left == nullptr && right == nullptr;
}

BinaryTree::BinaryTree(TreeNode *p)
{
    root = p;
}
BinaryTree::~BinaryTree()
{
    /**
     * postorderTraverse(pre in level) then delete(value)
     * However, we really encourage you to write recursive destructor code to destruct the whole tree. 
     */
}

void BinaryTree::print()
{
    TreeNode *node = root;
    preOrderPrintHelper(node);
}
void BinaryTree::preOrderPrintHelper(TreeNode *node)
{
    if (node != nullptr)
    {
        cout << node->data << ", ";
        preOrderPrintHelper(node->left);
        preOrderPrintHelper(node->right);
    }
}
void BinaryTree::preOrderPrintHelper2(TreeNode *node)
{
    cout << node->data << ", ";
    if (node->left != nullptr)
        preOrderPrintHelper(node->left);
    if (node->right != nullptr)
        preOrderPrintHelper(node->right);
}

bool BinaryTree::contains(int value)
{
    TreeNode *node = root;
    return containsHelper(node, value);
}
//我一开始的思路还是加rootGetter()，这样在client.cpp中就能通过rootGetter()返回得到root,也就在调用方法的时候有参数给方法传了。
//刚才一个激灵想起来，Matty讲的，'少参数'就再把'多参数'的写成'少参数'的helper函数，然后在函数中调用helper函数。
bool BinaryTree::containsHelper(TreeNode *node, int value)
{
    if (node == nullptr) //a nice if conditional, leaf node as basic case in recursive.
        return false;
    if (node->data == value)
        return true;
    else
    {
        return containsHelper(node->left, value) || containsHelper(node->right, value);
    }
}
void BinaryTree::printSideways()
{
    printSidewaysHelper(root, ""); // additional information!!! backtracking(a.k.a. trackback) choose,explore,unchoose
    cout << endl;
    printSidewaysHelper2(root, "");
}
void BinaryTree::printSidewaysHelper(TreeNode *node, string indent)
{
    if (node->right != nullptr)
    {
        printSidewaysHelper(node->right, indent + "    ");
    }
    cout << indent << node->data << endl;
    if (node->left != nullptr)
    {
        printSidewaysHelper(node->left, indent + "    ");
    }
}
void BinaryTree::printSidewaysHelper2(TreeNode *node, string indent)
{
    if (node->right != nullptr)
    {
        indent += "    ";                         //choose
        printSidewaysHelper(node->right, indent); //explore
        //unchoose, 删除"    "。临时用了loop这种傻大办法。
        for (int i = 0; i < 4; i++)
            indent.pop_back();
    }
    cout << indent << node->data << endl;
    if (node->left != nullptr)
    {
        indent += "    ";
        printSidewaysHelper(node->left, indent);
        for (int i = 0; i < 4; i++)
            indent.pop_back();
    }
}

void BinaryTree::addBinarySearchTreeNode(int value)
{
    if (root == nullptr)
    {
        root = new TreeNode(value);
        return;
    }
    TreeNode *node = root;
    while (true)
    {
        if (value == node->data)
            return;
        if (value < node->data)
        {
            if (node->left != nullptr)
                node = node->left;
            else
            {
                node->left = new TreeNode(value);
                break;
            }
        }
        if (value > node->data)
        {
            if (node->right != nullptr)
                node = node->right;
            else
            {
                node->right = new TreeNode(value);
                break;
            }
        }
    }
}
void BinaryTree::addBinarySearchTreeNode2(int value) //use recursive
{
    if (root == nullptr)
    {
        root = new TreeNode(value);
        return;
    }
    TreeNode *node = root;
    addBinarySearchTreeNode2Helper(node, value);
}
void BinaryTree::addBinarySearchTreeNode2Helper(TreeNode *node, int value)
{
    /**
     * write code like 'if(node == nullptr)' is wrong! because without '&', this function is passing by value, so node is like an exteranl pointer.
     * 
     * However, you can write code like this:
     * addBinarySearchTreeNode3Helper(TreeNode *&node, int value) // & 
     * if(node == nullptr)
     *      node = new TreeNode(value);
     * We encourage and recommend you write code like above just as in preordertraverse/preorderprint.
     */
    //base case
    if (node->left == nullptr || node->right == nullptr) //有vacant position
    {
        if (value < node->data)
        {
            node->left = new TreeNode(value);
            return;
        }
        if (value > node->data)
        {
            node->right = new TreeNode(value);
            return;
        }
        //if value == node->data, i.e. duplicate, we do nothing.
    }
    //recursive
    if (value < node->data)
        addBinarySearchTreeNode2Helper(node->left, value);
    if (value > node->data)
        addBinarySearchTreeNode2Helper(node->right, value);
}

TreeNode *BinaryTree::createBinarySearchTree(vector<int> &vec)
{
    for (auto element : vec)
        addBinarySearchTreeNode(element);
    return root;
}

bool BinaryTree::isInBinarySearchTree(int value)
{
    TreeNode *node = root;
    return isInBinarySearchTreeHelper(node, value);
}
bool BinaryTree::isInBinarySearchTreeHelper(TreeNode *node, int value)
{
    if (node == nullptr)
        return false;
    if (value == node->data)
        return true;
    else if (value < node->data)
        return isInBinarySearchTreeHelper(node->left, value); //李葆春,大山坡的春。递归是高度相信自己。
    else if (value > node->data)                              //node->data > value
        return isInBinarySearchTreeHelper(node->right, value);
}
bool BinaryTree::isInBinarySearchTree2(int value)
{
    TreeNode *current = root;
    while (true)
    {
        if (current == nullptr)
            return false;
        if (value == current->data)
            return true;
        else if (value < current->data)
        {
            current = current->left;
            continue;
        }
        else if (value > current->data)
        {
            current = current->right;
            continue;
        }
    }
    return false;
}
/**
 * 选择value那个node的"右子树"的最小值，即右子树的最左node的value来代替。注意那个node可能是个叶子(没有右子树)，可能它的右子树仅有一个结点，可能是个多结点的右子树，所以要分情况讨论。
 * 也可以选择"左子树"的最大值，即左子树的最右node。
 */
void BinaryTree::deleteBinarySearchTreeNode(int value)
{
    if (!isInBinarySearchTree(value))
    {
        cout << "No node in BST has such value" << endl;
        return;
    }

    TreeNode *current = isInPosition(root, value);

    if (current->isLeaf())
    {
        TreeNode *parentPointer = isInParentPosition(root, value);
        if (parentPointer->left == current)
        {
            TreeNode *trash = parentPointer->left;
            parentPointer->left = nullptr;
            delete trash;
        }
        if (parentPointer->right == current)
        {
            TreeNode *trash = parentPointer->right;
            parentPointer->right = nullptr;
            delete trash;
        }
        return;
    } // case 1: such as delete value 1
    if (current->right == nullptr)
    {
        TreeNode *parentPointer = isInParentPosition(root, value);
        parentPointer->left = current->left;
        delete current;
        return;
    } // case 2: such as delete value 3
    if (current->right->isLeaf())
    {
        current->data = current->right->data;
        TreeNode *trash = current->right;
        current->right = nullptr;
        delete trash;
        return;
    } // case 3: such as delete value 21

    //if current->right is a tree(>=one node的tree). //case 4
    TreeNode *lsmleaf = leftSecondMostLeaf(current->right);
    int tmp = current->data;
    current->data = lsmleaf->left->data;
    lsmleaf->left->data = tmp;
    TreeNode *trash = lsmleaf->left;
    lsmleaf->left = nullptr;
    delete trash;
}

TreeNode *BinaryTree::isInParentPosition(TreeNode *node, int value)
{
    TreeNode *parent = nullptr;
    TreeNode *current = node;
    while (true)
    {
        if (current == nullptr)
            return nullptr;
        if (value == current->data)
            return parent;
        else if (value < current->data)
        {
            parent = current;
            current = current->left;
            continue;
        }
        else if (value > current->data)
        {
            parent = current;
            current = current->right;
            continue;
        }
    }
    //return parent;
}

TreeNode *BinaryTree::isInPosition(TreeNode *node, int value)
{
    TreeNode *current = node;
    while (true)
    {
        if (current == nullptr)
            return nullptr;
        if (value == current->data)
            return current;
        else if (value < current->data)
        {
            current = current->left;
            continue;
        }
        else if (value > current->data)
        {
            current = current->right;
            continue;
        }
    }
    //return current;
}
TreeNode *BinaryTree::leftSecondMostLeaf(TreeNode *node)
{
    TreeNode *leftSecondMostLeaf = nullptr;
    TreeNode *current = node;
    while (!current->left->isLeaf())
    {
        current = current->left;
    }
    leftSecondMostLeaf = current;
    return leftSecondMostLeaf;
}
TreeNode *BinaryTree::rightMostLeaf(TreeNode *node)
{
    TreeNode *rightMostLeaf = nullptr;
    TreeNode *current = node;
    while (!current->isLeaf())
    {
        current = current->right;
    }
    rightMostLeaf = current;
    return rightMostLeaf;
}