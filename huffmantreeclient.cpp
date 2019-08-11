#include <iostream>
#include "HuffmanTree.h"
#include <array>

using namespace std;

int min(int a, int b);

int main()
{
    array<char, 14> characterArray{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'};
    array<int, 14> priorityArray{1, 4, 8, 7, 5, 6, 11, 48, 15, 32, 45, 3, 2, 9};
    priority_queue<HuffmanTreeNode *> mypq;
    for (int i = 0; i < min(characterArray.size(), priorityArray.size()); i++)
    {
        cout << characterArray[i] << "  " << priorityArray[i] << endl;
        HuffmanTreeNode *huffTreeNode = new HuffmanTreeNode(characterArray[i], priorityArray[i]);
        mypq.push(huffTreeNode); //用于维持有序(order)，任何增删改都要重新排序，以维持有序。
        delete huffTreeNode;
    }
    HuffmanTree huffTree;
    //huffTree.createHuffmanTree(mypq);
    return 0;
}

int min(int a, int b)
{
    return a < b ? a : b;
}