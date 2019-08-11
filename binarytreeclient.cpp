#include <iostream>
#include <string>
#include "BinaryTree.h"

using namespace std;

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
    BinaryTree binaryTree(root);
    binaryTree.printSideways();

    return 0;
}