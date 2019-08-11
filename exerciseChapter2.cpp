#include <stack>
#include <vector>
#include <array>
#include <list>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <iterator>
#include <tuple>
#include <utility>
#include <cctype>

using namespace std;

bool vowelCheck(string str);
bool beginWithVowel(string str);
string strTranslate(string str);
template <typename T, class t>
bool isIn(T container, t element);
vector<string> splitStringWithToken2(string str, char token);
vector<string> splitStringWithToken(string str, char token);

int main()
{
    string myString;
    getline(cin, myString);
    vector<string> vec1 = splitStringWithToken(myString, ' ');
    vector<string> vec2 = splitStringWithToken2(myString, ' ');
    for (string str : vec1)
        cout << strTranslate(str) << " ";
    cout << endl;
    for (string str : vec2)
        cout << strTranslate(str) << " ";
    cout << endl;
    return 0;
}

string strTranslate(string str)
{
    if (!vowelCheck(str))
    {
        return str;
    }
    else if (beginWithVowel(str))
    {
        return str + "way";
    }
    else if (!beginWithVowel(str))
    {
        string temporaryString = "";
        string vowelAlp = "aeiouAEIOU";
        int index = 0;
        for (auto iter = str.begin(); iter != str.end(); iter++, index++)
        {
            if (!isIn<string, char>(vowelAlp, *iter))
                temporaryString += *iter;
            else
                break;
        }
        return str.substr(index) + temporaryString + "ay";
    }
}

bool vowelCheck(string str)
{
    string vowelAlp = "aeiouAEIOU";
    for (auto it = vowelAlp.begin(); it != vowelAlp.end(); it++)
    {
        if (str.find(*it) != string::npos)
            return true;
    }
    return false;
}

bool beginWithVowel(string str)
{
    string vowelAlp = "aeiouAEIOU";
    return isIn<string, char>(vowelAlp, *str.begin());
}

template <typename T, class t>
bool isIn(T container, t element)
{
    for (auto iter = container.begin(); iter != container.end(); iter++)
    {
        if (element == *iter)
            return true;
    }
    return false;
}
/**
 * two kinds of implementation
 */
vector<string> splitStringWithToken(string str, char token)
{
    vector<string> vec;
    string temporaryString = "";
    int frontIndex = 0;
    int backIndex = 0;
    for (auto iter = str.begin(); iter != str.end(); iter++, backIndex++)
    {
        if (*iter == token)
        {
            temporaryString = str.substr(frontIndex, backIndex - frontIndex);
            vec.push_back(temporaryString);
            frontIndex = backIndex + 1;
        }
    }
    temporaryString = str.substr(frontIndex, backIndex - frontIndex);
    vec.push_back(temporaryString);
    return vec;
}

vector<string> splitStringWithToken2(string str, char token)
{
    vector<string> vec;
    string temporaryString = "";
    for (auto iter = str.begin(); iter != str.end(); iter++)
    {
        if (*iter == token)
        {
            vec.push_back(temporaryString);
            temporaryString = "";
            continue;
        }
        if (isalnum(*iter) || (*iter == '-')) //撇去除连词符之外的标点符号
        {
            temporaryString += *iter;
        }
    }
    if (isalnum(*str.end()))
        vec.push_back(str.substr(str.rfind(token) + 1));
    else
    {
        str.pop_back();
        vec.push_back(str.substr(str.rfind(token) + 1));
    }
    return vec;
}
