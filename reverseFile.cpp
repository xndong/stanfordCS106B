#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

string promptUserForFile(ifstream &inputFileStream, string prompt = "");
void readEntireFile(istream &stream, vector<string> &vec);
void readEntireFile2(istream &stream, vector<int> &vec);
int getInteger(string prompt);
int getInteger2(string prompt);
int stringToInteger(string str);

int main()
{
    ifstream inputFileStream;
    vector<string> vecStr;
    promptUserForFile(inputFileStream);
    readEntireFile(inputFileStream, vecStr);
    inputFileStream.close();
    for (auto strElement : vecStr)
        cout << strElement << endl;

    vector<int> vecInt;
    promptUserForFile(inputFileStream);
    readEntireFile2(inputFileStream, vecInt);
    int sum = 0;
    for (auto intElement : vecInt)
        sum += intElement;
    cout << sum << endl;
    inputFileStream.close();

    return 0;
}

string promptUserForFile(ifstream &inputFileStream, string prompt)
{
    while (true)
    {
        if (prompt == "")
            cout << "Input File Name: ";
        else
            cout << prompt;
        string filename;
        getline(cin, filename); //cin >> filename;cin不好因为万一文件名有空格怎么办
        inputFileStream.open(filename.c_str());
        if (!inputFileStream.fail())
            return filename;
        inputFileStream.clear();
        cout << "Errors occurs when opeing files" << endl;
    }
}

void readEntireFile(istream &stream, vector<string> &vec)
{
    string lineString;
    while (getline(stream, lineString))
    {
        vec.push_back(lineString);
    }
}
//--------------------------------------------------------------------------------
void readEntireFile2(istream &stream, vector<int> &vec)
{
    string lineString;
    int integerValue;
    while (getline(stream, lineString))
    {
        integerValue = stringToInteger(lineString);
        vec.push_back(integerValue);
    }
}

int getInteger(string prompt)
{
    int resultValue;
    while (true)
    {
        if (prompt == "")
            prompt = "Input an integer: ";
        cout << prompt;
        string inputString;
        getline(cin, inputString); //cin >> inputString;
        istringstream myStream(inputString);
        myStream >> resultValue >> ws;
        if (!myStream.fail() && myStream.eof())
            break;
        cout << "Error occurs when getting an integer, please try an input again!" << endl;
    }
    return resultValue;
}

int getInteger2(string prompt)
{
    int resultValue;
    while (true)
    {
        if (prompt == "")
            prompt = "Input an integer: ";
        cout << prompt;
        string inputString;
        getline(cin, inputString);
        istringstream myStream(inputString);
        myStream >> resultValue >> ws;
        if (!myStream.fail() && myStream.eof())
            return resultValue;
        cout << "Error occurs when getting an integer, please try an input again!" << endl;
    }
}

int stringToInteger(string str)
{
    int resultValue;
    istringstream myStringStream(str);
    myStringStream >> resultValue >> ws;
    if (myStringStream.fail() || !myStringStream.eof())
        cout << "Illegal integer format" << endl;
    return resultValue;
}
