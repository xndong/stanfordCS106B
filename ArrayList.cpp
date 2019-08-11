#include "ArrayList.h"

using namespace std;

ArrayList::ArrayList()
{
    //In constrcutors, we are supposed to implement member varibles if applicable or necessary.
    myElements = new int[100]();
    mySize = 0; //we can find that mySize是最后一个元素的下一个位置
    myCapacity = 100;
    //cout << "constructor is called!" << endl;
}
ArrayList::~ArrayList()
{
    /**
     * destructor和constructor一样，本职工作是处理each member variable。比如是否有member variable=new xxx，需要delete以防止memory leakage。
     * 
     * 对于Function scope{}中的things, we have two rules:
     * For thoese stack allocation, they are automatically destoryed after {} scope(i.e. when its life-cycle ends); 
     *   # When an object(arrayList) is destoryed, its destructor is called. I think it is because object is like a compounded thing. So we use a destructor to process its memeber varible. For each member varible, we still obey the two rules.
     *   # When a variable is destoryed, C++ memory management will free its memory. You don't care about them.
     * For heap allocation, they won't be automatically destoryed after {} scope, you need to 'delete' them in case of memory leakage.
     *   # When explictly 'delete' an object, its destructor is called. I think it is because object....
     *   # When explictly 'delete' a varible, we manually free the memory.
     */
    //cout << "destructor is called!" << endl;
    delete[] myElements;
}
/**
 * For stack allocation:
 *   #If an object:
 *   when declared, automatically call its constructor. I think its because object is like a compounded thing(including some member varibles), so we use constructor.
 *   when destoryed, automatically call its destructor. I think it is the same reason why we use destructor.
 *   #If a varible:
 *   when declared, C++ memory management automatically allocate memory
 *   when destoryed, C++ memory management automatically free memory
 * For heap allocation:
 *   #If an object:
 *   when 'new', its constructor is called;
 *   when 'delete', its destructor is called;
 *   #If a variable:
 *   'new' will manually allocated memory.
 *   'delete' will manually free memory.
 */
void ArrayList::add(int value)
{
    checkIfResize();
    myElements[mySize] = value;
    mySize++;
    //out of boundary
}
void ArrayList::clear()
{
    mySize = 0;
}
int ArrayList::get(int index) const
{
    return myElements[index];
}
void ArrayList::set(int index, int value)
{
    myElements[index] = value;
}
void ArrayList::insert(int index, int value)
{
    checkIfResize();
    for (int i = mySize; i > index; i--)
    {
        myElements[i] = myElements[i - 1];
    }
    myElements[index] = value;
    mySize++;
}
bool ArrayList::isEmpty() const
{
    if (mySize == 0)
        return true;
    return false;
}
void ArrayList::remove(int index)
{
    for (int i = index; i < mySize - 1; i++)
    {
        myElements[i] = myElements[i + 1];
    }
    mySize--;
}
int ArrayList::size() const
{
    return mySize;
}
int ArrayList::capacity() const
{
    return myCapacity;
}
void ArrayList::debug() const
{
}
void ArrayList::checkIfResize()
{
    if (mySize == myCapacity)
    {
        myCapacity *= 2;
        //allocate a new large memory with a larger array 'bigger'
        int *bigger = new int[myCapacity];
        //copy data from original memory(array)
        for (int i = 0; i < mySize; i++)
            bigger[i] = myElements[i];
        //delete original memory to avoid memory leak
        delete[] myElements;
        //assign new allocated memory/ array 'bigger' to original array
        myElements = bigger;
    }
}

ostream &operator<<(ostream &out, ArrayList &list)
{
    for (int i = 0; i < list.size(); i++)
    {
        out << list.get(i) << " ";
    }
    return out;
}