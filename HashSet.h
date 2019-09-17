#ifndef _hashset_h
#define _hashset_h
#include <vector>
#include <string>
using namespace std;
struct HashNode
{
    HashNode(int data = 0, HashNode *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
    /**
     * constructor——to initialize the member varibles(member varibles, here, are data and next) in a class(in c++ structure is a class)
     * constructor,destructor可以在类的外部(eg .cpp file中)实现，也可以在类的内部实现(eg这里)。
     * 声明可以多处多次，但实现只能一处（i.e.一次)。
    */
    ~HashNode();
    int data;
    HashNode *next;
};
class HashSet
{
public:
    //constructors and destructors
    HashSet(int capacity = 10, int mySize = 0);
    ~HashSet();
    //member functions
    void add(int value);
    void clear();
    bool contains(int value) const;
    void printStructure() const;
    void remove(int value);

private:
    //member varibles
    int capacity;
    int mySize;
    vector<HashNode *> buckets; //equals to: HashNode **buckets or HashNode*[] buckets, because 'int[] array' equals to 'int *array'
    //member functions            Note that it not pointer of pointers, and it array(vector) of pointers(HashNode*).
    int hashCode(int value) const;
};
#endif

/**
 * HashSet的核心数据结构(内部结构,internal structure)是一个bucket,这个buckets是一个vector,
 * vector的元素是HashNode *类型，HashNode *不就和我们以前学的LinkedList里ListNode *一样么~
 * 所以vector的元素是一个LinkedList,这个LinkedList的动机也是解决hash collision. We called this idea 'separate chain'
 * vesus the previous method 'probing' including linear probing and quadratic probing.

 * HashSet video中hashCode()是简单的取模  ---> 到了书中HashMap, hashCode()是个expert designed function.
 * HashSet video中使用dynamic raw array  ---> 到了HashMap,改成vector.
 * 书的思路十分清晰：从简单到复杂，把知识一点点引进来，带你一点点升级，写法越来越越摆脱使用naive的结构、方法。
*/