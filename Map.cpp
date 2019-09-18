#include <iostream>
#include <string>
#include "Map.h"
using namespace std;

TreeNode::TreeNode(string key, int value)
{
    this->key = key;
    this->value = value;
    this->leftchild = nullptr;
    this->rightchild = nullptr;
}
TreeNode::~TreeNode()
{
}

BST::BST(TreeNode *root)
{
    this->root = root;
}
BST::BST(string key, int value)
{
    this->root = new TreeNode(key, value);
}
BST::~BST()
{
}
void BST::add(string key, int value)
{
}
void BST::remove(string key)
{
}
bool BST::contains(int key)
{
}
void BST::preorderTraverse()
{
}

//--------------------------------AVL-----------------------------------
AVL::AVL(TreeNode *root)
{
    this->root = root;
}
AVL::AVL(string key, int value)
{
    this->root = new TreeNode(key, value);
}
AVL::~AVL()
{
}
void AVL::add(string key, int value)
{
}
void AVL::remove(string key)
{
}
bool AVL::contains(int key)
{
}
void AVL::preorderTraverse()
{
}