#include <iostream>
#include <string>
#include <vector>

using namespace std;

void sublist(vector<string> &stringVec);
void sublistHelper(vector<string> &stringVec, vector<string> &chosen);
void sublistHelper2(vector<string> &stringVec, vector<string> &chosen);
void printVector(vector<string> &vecString);

int main()
{
    vector<string> stringVec;
    string name;
    for (int i = 0; i < 4; i++)
    {
        cin >> name;
        stringVec.push_back(name);
    }
    sublist(stringVec);
    return 0;
}

void sublist(vector<string> &stringVec)
{
    vector<string> chosen;
    sublistHelper(stringVec, chosen);
    sublistHelper2(stringVec, chosen);
}

void sublistHelper(vector<string> &stringVec, vector<string> &chosen)
{
    if (stringVec.empty())
    {
        printVector(chosen);
    }
    else
    {
        string firstString = stringVec[0];
        stringVec.erase(stringVec.begin());
        chosen.push_back(firstString);    //choose
        sublistHelper(stringVec, chosen); //explore choice-'with'
        chosen.pop_back();                //unchoose
        stringVec.insert(stringVec.begin(), firstString);

        stringVec.erase(stringVec.begin());
        //不choose 'Jane'。chosen.push_back(空)，什么也不要push。什么也不做，所以就没有代码。
        sublistHelper(stringVec, chosen); //explore choice-'withou'
        //前面不choose Jane,这里回溯时当然也没有能pop出来的东西，chosen.pop_back(空)。什么也不做，所以就没有代码。
        stringVec.insert(stringVec.begin(), firstString);
    }
}
/**
 *      stringVec.insert(0, firstString);

        stringVec.erase(0, 1);
        可以抵消掉。所以sublistHelper可以写成sublistHelper2(i.e. standford lecture video给出的solution)。

        需要明白的是，sublistHelper是回溯代码的根本上的pattern。如果把之前例子中的loop进行循环展开，我们能发现它的pattern就是长sublistHelper这个样子，
        只不过我们按照sublistHelper这个pattern写写写，最后发现刚好能把代码压缩精简，改写成for-loop的形式。（这里这个sublistHelper的例子就没法改写成loop）
        另一方面，“抵消”也是按照sublistHelper这个pattern写写写，最后发现有几行代码可以“抵消”掉，然后我们就改写了一下，比如sublistHelper2。
        可见，无论是for-loop还是抵消，都是按照sublistHelper这一根本的code pattern,只是写的过程中，我们会发现咦，有的example可以直接写成loop,有的代码可以“抵消” etc。
 */
void sublistHelper2(vector<string> &stringVec, vector<string> &chosen)
{
    if (stringVec.empty())
    {
        printVector(chosen);
    }
    else
    {
        string firstString = stringVec[0];
        stringVec.erase(stringVec.begin());
        chosen.push_back(firstString);    //choose
        sublistHelper(stringVec, chosen); //explore choice-'with'
        chosen.pop_back();                //unchoose
        //stringVec.insert(0, firstString);

        //stringVec.erase(0, 1);
        //不choose 'Jane'。chosen.push_back(空)，什么也不要push。什么也不做，所以就没有代码。
        sublistHelper2(stringVec, chosen); //explore choice-'without'
        //前面不choose Jane,这里回溯时当然也没有能pop出来的东西，chosen.pop_back(空)。什么也不做，所以就没有代码。
        stringVec.insert(stringVec.begin(), firstString);
    }
}

void printVector(vector<string> &vecString)
{
    cout << "{";
    for (auto vecElement : vecString)
        cout << vecElement << ",";
    cout << "}" << endl;
}