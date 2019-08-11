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
#include <map>
#include <utility>
#include <cstdlib>

using namespace std;
bool startsWith(string str, string suffix);
bool startsWith(string str, char suffix);
string subString(string str, size_t position, size_t length);
string capitalize(string str);
int scrabbleGame(string word);
int scrabbleGame2(string word);
void replaceAll(string &str, string s1, string s2);
string replaceAll2(string str, string s1, string s2);
string replaceAll3(string str, string s1, string s2);
string stripPunc(string str);
string stripPunc2(string str);
bool isSentencePalindrome(string str);
bool isVowel(char c);
string obenglobish(string word);
string reverseDNAString(string str);
int findDNAMatch(string s1, string s2, int start = 0);
void error(string msg);

int main()
{
    while (true)
    {
        string word;
        getline(cin, word);
        if (word == "")
        {
            error("wrong input");
        }
        string trans = obenglobish(word);
        cout << word << " -> " << trans << endl;
    }
    return 0;
}

/**problem 1*/
bool startsWith(string str, string suffix)
{
    if (str.length() < suffix.length())
        return false;
    for (int i = 0; i < suffix.length(); i++)
    {
        if (str[i] != suffix[i])
            return false;
    }
    return true;
}

bool startsWith(string str, char suffix)
{
    if (*str.end() != suffix)
        return false;
    else
        return true;
}

/**problem 3 */
string subString(string str, size_t position, size_t length)
{
    string resultString = "";
    if (position > str.length())
        cerr << "starting position is out of bound!";
    if (length >= str.length())
        length = str.length() - position;
    for (size_t i = position; i < position + length; i++)
    {
        resultString += str.at(i);
    }
    return resultString;
}

/**problem 4 */
string capitalize(string str)
{
    string resultStr = "";
    if (!isalpha(*str.begin()))
        return resultStr;
    resultStr = toupper(str[0]);
    for (auto iter = str.begin() + 1; iter != str.end(); iter++)
    {
        resultStr += tolower(*iter);
    }
    return resultStr;
}

/*problem 5 */
int scrabbleGame(string word)
{
    int score = 0;
    string newWord = "";
    for (auto iter = word.begin(); iter != word.end(); iter++)
        newWord += toupper(*iter);
    map<char, int> scrabbleScoreMap = {{'A', 1}, {'E', 1}, {'I', 1}, {'L', 1}, {'N', 1}, {'O', 1}, {'R', 1}, {'S', 1}, {'T', 1}, {'U', 1}};
    scrabbleScoreMap.insert(pair<char, int>('D', 2));
    scrabbleScoreMap.insert(pair<char, int>('G', 2));
    scrabbleScoreMap.insert(pair<char, int>('B', 3));
    scrabbleScoreMap.insert(pair<char, int>('C', 3));
    scrabbleScoreMap.insert(pair<char, int>('M', 3));
    scrabbleScoreMap.insert(pair<char, int>('P', 3));
    scrabbleScoreMap.insert(make_pair('F', 4));
    scrabbleScoreMap.insert(make_pair('H', 4));
    scrabbleScoreMap.insert(make_pair('V', 4));
    scrabbleScoreMap.insert(make_pair('W', 4));
    scrabbleScoreMap.insert(make_pair('Y', 4));
    scrabbleScoreMap.insert(pair<char, int>('K', 5));
    scrabbleScoreMap.insert(pair<char, int>('J', 8));
    scrabbleScoreMap.insert(pair<char, int>('X', 8));
    scrabbleScoreMap.insert(make_pair('Q', 10));
    scrabbleScoreMap.insert(make_pair('Z', 10));
    for (auto iter = newWord.begin(); iter != newWord.end(); iter++)
    {
        if (!isalpha(*iter))
            continue;
        score += scrabbleScoreMap[*iter];
    }
    return score;
}
int scrabbleGame2(string word)
{
    int score = 0;
    string newWord = "";
    for (auto iter = word.begin(); iter != word.end(); iter++)
    {
        switch (toupper(*iter))
        {
        case 'A':
        case 'E':
        case 'I':
        case 'L':
        case 'N':
        case 'O':
        case 'R':
            score += 1;
            break;
        case 'D':
        case 'G':
            score += 2;
            break;
        case 'B':
        case 'C':
        case 'M':
        case 'P':
            score += 3;
            break;
        case 'F':
        case 'H':
        case 'V':
        case 'W':
        case 'Y':
            score += 4;
            break;
        case 'K':
            score += 5;
            break;
        case 'J':
        case 'X':
            score += 8;
            break;
        case 'Q':
        case 'Z':
            score += 10;
            break;
        }
    }
    return score;
}

/**problem 10 */
void replaceAll(string &str, string s1, string s2)
{
    while (str.find(s1) != string::npos)
        str.replace(str.find(s1), s1.length(), s2);
} //student->phd student会出现死循环
string replaceAll2(string str, string s1, string s2)
{
    string resultString = str;
    while (resultString.find(s1) != string::npos)
        resultString.replace(resultString.find(s1), s1.length(), s2);
    return resultString;
} //student->phd student会出现死循环
string replaceAll3(string str, string s1, string s2)
{
    string resultString = str;
    size_t index = 0;
    while (true)
    {
        if (resultString.find(s1, index) == string::npos)
            break;
        else
        {
            index = resultString.find(s1, index);
            resultString.replace(index, s1.length(), s2);
            index += s2.length();
        }
    }
    return resultString;
} //student->phd student不会出现死循环

/**problem 11 */
string stripPunc(string str)
{
    for (auto iter = str.begin(); iter != str.end(); iter++)
    {
        if (!isalnum(*iter))
        {
            str.erase(iter); //iter=str.erase(iter);
            iter--;
            continue;
        }
        *iter = toupper(*iter);
    }
    return str;
}

string stripPunc2(string str)
{
    for (auto iter = str.begin(); iter != str.end();)
    {
        if (!isalnum(*iter))
        {
            iter = str.erase(iter);
        }
        else
        {
            *iter = toupper(*iter);
            iter++;
        }
    }
    return str;
}
bool isSentencePalindrome(string str)
{
    if (str.length() == 1)
        return true;
    else if (str.length() == 2 && (str.front() == str.back()))
        return true;
    else
    {
        return isSentencePalindrome(str.substr(1, str.length() - 2)) && (str.front() == str.back());
    }
}

/**problem 16 */
string obenglobish(string word)
{
    string resultString = "";
    //grow a string as the return result
    for (auto iter = word.begin(); iter != word.end(); iter++)
    {
        if (isVowel(*iter))
        {
            if (iter != word.end() - 1 && isVowel(*(iter - 1))) //except one
                resultString += *iter;
            else if (iter == word.end() - 1 && (word.back() == 'e' || word.back() == 'E')) //except one
                resultString += *iter;
            else
                resultString = resultString + "ob" + *iter;
        }
        else
            resultString += *iter;
    }
    return resultString;
}

bool isVowel(char c)
{
    switch (c)
    {
    case 'A':
    case 'a':
    case 'E':
    case 'e':
    case 'I':
    case 'i':
    case 'O':
    case 'o':
    case 'U':
    case 'u':
        return true;
    }
    return false;
}

/**problem 20 */
int findDNAMatch(string s1, string s2, int start)
{
    int index = s1.find(reverseDNAString(s2), start);
    if (index != string::npos)
        return index;
    else
        return -1;
}

string reverseDNAString(string str)
{
    for (auto iter = str.begin(); iter != str.end(); iter++)
    {
        switch (*iter)
        {
        case 'A':
            *iter = 'T';
            continue; // break continue
        case 'T':
            *iter = 'A';
            continue;
        case 'G':
            *iter = 'C';
            continue;
        case 'C':
            *iter = 'G';
            continue;
        }
    }
    return str;
}

void error(string msg)
{
    cerr << msg << endl;
    exit(EXIT_FAILURE);
    return;
}