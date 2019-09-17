#include <iostream>
#include <vector>
#include <string>
#include "HashMap.h"

using namespace std;

int main()
{
    string city[13] = {
        "beijing",
        "qingdao",
        "shanghai",
        "suzhou",
        "qingdao",
        "shanghai",
        "suzhou",
        "hongkong",
        "changsha",
        "shenzhen",
        "hangzhou",
        "xian",
        "yantai"};
    int code[13] = {17, 41, 9, 29, 41, 9, 29, 37, 81, 69, 20, 42, 55};
    string notfound[3] = {"chengdu", "dalian", "haikou"};
    HashMap hashmap;
    for (int i = 0; i < 13; i++)
    {
        hashmap.add(city[i], code[i]);
    }
    hashmap.printStructure();
    hashmap.calculateLoadFactor();

    bool flag = hashmap.contains("chengdu");
    cout << boolalpha << flag << endl;

    hashmap.remove("suzhou");
    hashmap.remove("hangzhou");
    hashmap.remove("qingdao");
    hashmap.printStructure();

    //hashmap.clear();
    //hashmap.printStructure();
    return 0;
}