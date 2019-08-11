#ifndef _huffmantree_h
#define _huffmantree_h
#include <string>
#include <queue>

using namespace std;

struct HuffmanTreeNode
{
    //constructor and destructor
    HuffmanTreeNode(char c, int priorityValue, HuffmanTreeNode *leftPointer = nullptr, HuffmanTreeNode *rightPointer = nullptr);
    ~HuffmanTreeNode();
    //member varibles
    int priority;
    char character;
    HuffmanTreeNode *left;
    HuffmanTreeNode *right;
    //member functions
    bool isLeaf();
};

class HuffmanTree
{
public:
    //constructor and destructor
    HuffmanTree(HuffmanTreeNode *p = nullptr);
    ~HuffmanTree();
    //member functions
    void createHuffmanTree(priority_queue<HuffmanTreeNode *> pq); //所有character都在叶子结点，这是create算法(4 steps, second step)决定的。
    string printEncode(char c);                                     //实际上也就是find/search c的过程。由于不是BST，所以只好traverse search。
    string encodeToCompress(string stringToBeEncoded);            //使用created的HuffmanTree来将字符串encode成bit。
    string decodeToDecompress(string bitToBeDecoded);             //使用created的HuffmanTree将bit stream decode成字符串。

    /**
     * A huffman tree is an encoding and decoding tree. Specifically, it is a pattern for 'you' to follow when encoding and decoding,
     * Thus creating a huffman tree is always the first work to do. 
     * When a huffman tree is created, then you can encode or decode by using the created huffman tree.
     *  
     * 我一开始想这还怎么decode回来，怎么知道从哪里断开,后来一个机灵，
     * 显然将stream不断输入HuffmanTree里直到遇到叶子结点就可以了。
     * 
     * 另一方面，我担心的问题抽象一下就是x的code是y的code的字串，
     * 但是由于x, y(any character)在HuffmanTree里都是叶子结点，所以不可能出现字串。
     */

private:
    //member varibles
    HuffmanTreeNode *root;
    //member functions
    string printEncodeHelper(HuffmanTreeNode *node, char c, string s = "");
    string encodeToCompressHelper(HuffmanTreeNode *node, string stringToBeEncoded);
    string decodeToDecompressHelper(HuffmanTreeNode *node, string bitToBeDecoded);
};

#endif