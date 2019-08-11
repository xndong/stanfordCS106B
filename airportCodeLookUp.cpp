#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <utility>
#include <cctype>
using namespace std;

string promptUserForFile(ifstream &inputFileStream, string prompt = "");
void readAirPortCode(ifstream &inputFileStream, map<string, string> &airportCodeMap);
void processLine(map<string, string> &myMap, string line);
string lookUpAirportCodeMap(map<string, string> &airportCodeMap);

const int AIRPORTCODE_POSITION = 0;
const int AIRPORTCODE_LENGTH = 3;
const int AIRPORTDETAIL_POSITION = 4;

int main()
{
    map<string, string> airportCodeMap;
    ifstream inputFileStream;
    readAirPortCode(inputFileStream, airportCodeMap);
    cout << lookUpAirportCodeMap(airportCodeMap) << endl;
    return 0;
}

void readAirPortCode(ifstream &inputFileStream, map<string, string> &airportCodeMap)
{
    string eachline;
    promptUserForFile(inputFileStream);
    while (getline(inputFileStream, eachline))
    {
        processLine(airportCodeMap, eachline);
    }
}

void processLine(map<string, string> &myMap, string line)
{
    string code = line.substr(AIRPORTCODE_POSITION, AIRPORTCODE_LENGTH);
    string detail = line.substr(AIRPORTDETAIL_POSITION);
    myMap.insert(make_pair(code, detail));
}

string promptUserForFile(ifstream &inputFileStream, string prompt)
{
    while (true)
    {
        if (prompt == "")
            prompt = "Input File Name: ";
        cout << prompt;
        string filename;
        getline(cin, filename);
        inputFileStream.open(filename.c_str());
        if (!inputFileStream.fail())
            return filename;
        inputFileStream.clear();
        cout << "Error occurs when opeing files." << endl;
    }
}

string lookUpAirportCodeMap(map<string, string> &airportCodeMap)
{
    string lookUpResult;
    string userInputCode = "";
    string code = "";
    while (true)
    {
        cout << "Input Airport Code Abbreviation:";
        //userInputCode = "";
        getline(cin, userInputCode);
        for (auto element : userInputCode)
        {
            if (isalpha(element))
            {
                code += toupper(element);
            }
        }
        if (code.length() != AIRPORTCODE_LENGTH)
        {
            cout << "Wrong Airport Code Abbreviation, Please Check Your Input and Try Again!" << endl;
            continue;
        }
        if (!airportCodeMap.count(code))
        /**
         * find返回的是迭代器，如果没有找到就返回map::end()。
         * 这里的map::end()很妙，我之前还疑惑万一find的元素就在末尾该怎么办，恍然想起是[)半闭半开区间，末尾元素是map::end()-1。所以这里我才可以说我find不到我就给你返回map::end()迭代器提示你。
         */
        {
            cout << "Such Airport Code can not be found!" << endl;
            continue;
        }
        return airportCodeMap[code];
    }
}

/**
 * Test whether cin will append content instead of replace. Of course it won't!
 */

void printTestCin()
{
    string testStringOne = "";
    string testStringTwo = "ABCD";
    string testStringThree = "";
    string testStringFour = "ABCD";
    cin >> testStringOne;
    cin >> testStringTwo >> ws;
    getline(cin, testStringThree);
    getline(cin, testStringFour);
    cout << "testStringOne: " << testStringOne << endl;
    cout << "testStringTwo: " << testStringTwo << endl;
    cout << "testStringThree: " << testStringThree << endl;
    cout << "testStringFour: " << testStringFour << endl;
}