#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cctype>
using namespace std;
string promptUserForFile(ifstream &inputFileStream, string prompt = "");

int main()
{
    vector<int> alphFrequency(26, 0);
    ifstream inputFileStream;
    promptUserForFile(inputFileStream);
    char ch;
    while (inputFileStream.get(ch))
    {
        if (isalpha(ch))
        {
            ch = toupper(ch);
            alphFrequency[ch - 'A']++;
        }
    }
    inputFileStream.close();
    for (char indexLetter = 'A'; indexLetter <= 'Z'; indexLetter++)
    {
        cout << indexLetter << " : "
             << alphFrequency[indexLetter - 'A'] << endl;
    }
    return 0;
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
        cout << "Errors occurs when opeing files" << endl;
    }
}