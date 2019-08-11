#include "HeapBinaryTree.h"
#include <iostream>
#include <queue>

using namespace std;

TreeNode::TreeNode(int value, TreeNode *parentPointer, TreeNode *leftPointer, TreeNode *rightPointer)
{
    data = value;
    parent = parentPointer;
    left = leftPointer;
    right = rightPointer;
}
TreeNode::~TreeNode()
{
}

HeapBinaryTree::HeapBinaryTree(TreeNode *p)
{
    root = p;
}
HeapBinaryTree::~HeapBinaryTree()
{
}
bool HeapBinaryTree::isEmpty()
{
    if (root != nullptr)
        return true;
    return false;
}
void HeapBinaryTree::addHeapBinaryTreeNode(int value)
{
    if (root == nullptr)
    {
        root = new TreeNode(value);
        return;
    }

    TreeNode *node = root;
    queue<TreeNode *> bubbleUpQue;
    bubbleUpQue.push(node);
    while (true)
    {
        TreeNode *front = bubbleUpQue.front();
        if (front->left == nullptr || front->right == nullptr)
        {
            node = front;
            break;
        }
        bubbleUpQue.push(front->left);
        bubbleUpQue.push(front->right);
        bubbleUpQue.pop();
    }

    TreeNode *leaf = new TreeNode(value, node);
    if (node->left == nullptr)
    {
        node->left = leaf;
    }
    if (node->right == nullptr)
    {
        node->right = leaf;
    }

    //bubble-up
    TreeNode *current = leaf;
    while (current->parent != nullptr)
    {
        if (current->data < current->parent->data)
        {
            int tmp = current->data;
            current->data = current->parent->data;
            current->parent->data = tmp;
        }
    }
}
int HeapBinaryTree::topHeapBinaryTreeNode()
{
    return root->data;
}
void HeapBinaryTree::removeHeapBinaryTreeNode()
{
    // swap
    // delete 除了left和right，别忘了parent指针的处理
    //bubble-down
    TreeNode *current = root;
    while (current->left != nullptr && current->right != nullptr)
    {
        if (current->left->data < current->right->data)
        {
            int tmp = current->data;
            current->data = current->left->data;
            current->left->data = tmp;
        }
        else
        {
            int tmp = current->data;
            current->data = current->right->data;
            current->right->data = tmp;
        }
    }
    if (current->left != nullptr && current->data < current->left->data)
    {
        int tmp = current->data;
        current->data = current->left->data;
        current->left->data = tmp;
    }
}
void HeapBinaryTree::levelOrderHeapBinaryTree(TreeNode *root)
{
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty())
    {
        cout << que.front()->data << ", ";
        if (que.front()->left != nullptr)
            que.push(que.front()->left);
        if (que.front()->right != nullptr)
            que.push(que.front()->right);
        que.pop();
    }
}
void HeapBinaryTree::preOrderHeapBinaryTree(TreeNode *root)
{
    cout << root->data << ", ";
    if (root->left != nullptr)
    {
        preOrderHeapBinaryTree(root->left);
    }
    if (root->right != nullptr)
    {
        preOrderHeapBinaryTree(root->right);
    }
}
void HeapBinaryTree::inOrderHeapBinaryTree(TreeNode *root)
{

    if (root->left != nullptr)
        inOrderHeapBinaryTree(root->left);
    cout << root->data << ", ";
    if (root->right != nullptr)
        inOrderHeapBinaryTree(root->right);
}
TreeNode *HeapBinaryTree::rootGetter()
{
    return root;
}

void HeapBinaryTree::bubbleDown(TreeNode *node)
{
    if (node == nullptr)
        return;
    else
    {
        if (node->data > node->left->data)
        {
            int tmp = node->data;
            node->data = node->left->data;
            node->left->data = tmp;
            bubbleDown(node->left);
        }
        else
        {
            int tmp = node->data;
            node->data = node->right->data;
            node->right->data = tmp;
            bubbleDown(node->right);
        }
    }
}