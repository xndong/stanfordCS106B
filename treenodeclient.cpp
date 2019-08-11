#include <iostream>
#include <queue>
#include "TreeNode.h"

using namespace std;

void traverseLevelOrder(TreeNode *root); //层序遍历
void traversePreOrder(TreeNode *root);
void traverseInOrder(TreeNode *root);
void traversePostOrder(TreeNode *root);
void traversePreOrderCountLeaf(TreeNode *root, int &numbers);

int main()
{
    TreeNode *root = new TreeNode(12);
    root->left = new TreeNode(10);
    root->right = new TreeNode(18);
    root->left->left = new TreeNode(8);
    root->left->left->left = new TreeNode(4);
    root->left->left->left->left = nullptr;
    root->left->left->left->right = nullptr;
    root->left->left->right = nullptr;
    root->left->right = new TreeNode(11);
    root->left->right->left = nullptr;
    root->left->right->right = nullptr;
    root->right->left = new TreeNode(15);
    root->right->left->left = nullptr;
    root->right->left->right = nullptr;
    root->right->right = new TreeNode(36);
    root->right->right->left = nullptr;
    root->right->right->right = nullptr;
    /**
     *             12
     *       10           18
     *     8    11     15     36
     *  4
     */
    traverseLevelOrder(root);
    cout << endl;
    traversePreOrder(root);
    cout << endl;
    traverseInOrder(root);
    cout << endl;
    traversePostOrder(root);
    cout << endl;

    int numbers = 0;
    traversePreOrderCountLeaf(root, numbers);
    cout << numbers << endl;
    return 0;
}

//------------------------------------------------------------------------------------------------------------

void traverseLevelOrder(TreeNode *root) //层序遍历, a.k.a.Tree的BFS.
{
    queue<TreeNode *> que;
    que.push(root);
    while (!que.empty())
    {
        TreeNode *popNode = que.front();
        cout << popNode->data << " ";
        que.pop();                    //出队列
        if (popNode->left != nullptr) //如果有左孩子，左孩子进队列
            que.push(popNode->left);
        if (popNode->right != nullptr) //如果右孩子不为空，右孩子进队列
            que.push(popNode->right);
    }
}
void traversePreOrder(TreeNode *root) //先序、中序、后序遍历, a.k.a. Tree的DFS.
{
    cout << root->data << " ";
    if (root->left != nullptr)
        traversePreOrder(root->left);
    if (root->right != nullptr)
        traversePreOrder(root->right);
}
void traverseInOrder(TreeNode *root)
{
    if (root->left != nullptr)
        traverseInOrder(root->left);
    cout << root->data << " ";
    if (root->right != nullptr)
        traverseInOrder(root->right);
}
void traversePostOrder(TreeNode *root)
{
    if (root->left != nullptr)
        traversePostOrder(root->left);
    if (root->right != nullptr)
        traversePostOrder(root->right);
    cout << root->data << " ";
}

void traversePreOrderCountLeaf(TreeNode *root, int &numbers)
{
    if ((*root).isLeaf())
        numbers++;
    if (root->left != nullptr)
        traversePreOrderCountLeaf(root->left, numbers);
    if (root->right != nullptr)
        traversePreOrderCountLeaf(root->right, numbers);
}