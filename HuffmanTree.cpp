#include <iostream>
#include "HuffmanTree.h"

using namespace std;

HuffmanTreeNode::HuffmanTreeNode(char c, int priorityValue, HuffmanTreeNode *leftPointer, HuffmanTreeNode *rightPointer)
{
    priority = priorityValue;
    character = c;
    left = leftPointer;
    right = rightPointer;
}
HuffmanTreeNode::~HuffmanTreeNode()
{
}

bool HuffmanTreeNode::isLeaf()
{
    return left == nullptr && right == nullptr;
}

HuffmanTree::HuffmanTree(HuffmanTreeNode *p)
{
    root = p;
}
HuffmanTree::~HuffmanTree()
{
}

void HuffmanTree::createHuffmanTree(priority_queue<HuffmanTreeNode *> pq)
{
    //To do here
}

string HuffmanTree::printEncode(char c)
{
    if (root == nullptr)
    {
        cout << "Empty Huffman Tree!" << endl;
        return;
    }
    HuffmanTreeNode *node = root;
    string huffmanCode = "";
    return printEncodeHelper(node, c, huffmanCode);
}

string HuffmanTree::printEncodeHelper(HuffmanTreeNode *node, char c, string s)
{
    if (node == nullptr && node->character == 'c') //base case
    {
        cout << s << endl;
        return s;
    }
    else //recursive case
    {
        if (node != nullptr)
        {
            printEncodeHelper(node->left, c, s + "0");
            printEncodeHelper(node->right, c, s + "1");
        }
    }
}

string HuffmanTree::encodeToCompress(string stringToBeEncoded)
{
    HuffmanTreeNode *node = root;
    return encodeToCompressHelper(node, stringToBeEncoded);
}
string HuffmanTree::encodeToCompressHelper(HuffmanTreeNode *node, string stringToBeEncoded)
{
    string result = "";
    for (char c : stringToBeEncoded)
    {
        result += printEncode(c);
    }
    return result;
}

string HuffmanTree::decodeToDecompress(string bitToBeDecoded)
{
    if (root == nullptr)
    {
        cout << "Empty Huffman Tree!" << endl;
        return "";
    }
    HuffmanTreeNode *node = root;
    return decodeToDecompressHelper(node, bitToBeDecoded);
}
string HuffmanTree::decodeToDecompressHelper(HuffmanTreeNode *node, string bitToBeDecoded)
{
    string result = "";
    for (char c : bitToBeDecoded)
    {
        if (c == '0')
        {
            node = node->left;
        }
        else if (c == '1')
        {
            node = node->right;
        }
        if (node->isLeaf())
        {
            result.push_back(node->character);
            node = root;
        }
    }
    return result;
}

void stringToBit();
void bitToString();