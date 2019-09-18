/**
 * StringMap ---> SortedMap ---> Map(TreeMap) ---> HashMap
 *                SortedSet ---> Set(TreeSet) ---> HashSet
 * SortedMap or SortedSet 一直维持顺序(插入排序),通过这种方式，可以将get的复杂度降低到O(logN),但是put的复杂度依旧是O(N).
 * Of course, we can design 'StringSet', but given that StringMap is merely used to let us to know why should design Map(BST internally ---> AVL ---> 红黑树)
 * and why should design HashMap. Both reason is that we want to push the limit of the complexity of our algorithm in add, contains, remove to O(1).
 * It turns out we finally achieve our ojective by design these new data structures step by step.
*/
#ifndef _map_h
#define _map_h
#include <string>
#include <iostream>
using namespace std;

struct TreeNode
{
    TreeNode(string key = "", int value = 0);
    ~TreeNode();
    string key;
    int value;
    TreeNode *leftchild, *rightchild;
};
class BST
{
public:
    //constructors and destrcutors
    BST(TreeNode *root = nullptr);
    BST(string key, int value);
    ~BST();
    //member functions
    void add(string key, int value);
    void remove(string key);
    bool contains(int key);
    void preorderTraverse();

private:
    //member varibles
    TreeNode *root;
    //member functions
};

class AVL
{
public:
    //constructors and destructors
    AVL(TreeNode *root = nullptr);
    AVL(string key, int value);
    ~AVL();
    //member functions
    void add(string key, int value);
    void remove(string key);
    bool contains(int key);
    void preorderTraverse();

private:
    //member varibles
    TreeNode *root;
    //member functions
};

#endif