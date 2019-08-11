#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

int getInteger(string prompt = "");
void printProblem7();
void printTable();
void error(string errorMessage);
string longestLine(string filename);
int charsInLine(string line);
int wordsInLine(string line);
void count(ifstream &inputFileStream, string prompt = "");
void duplicateRead(ifstream &inputFileStream, string prompt = "");
void formattedStreamInput();

int main()
{
    ifstream inputFileStream;
    int value;
    int count = 0;
    inputFileStream.open("numbers.txt");
    while (!inputFileStream.eof())
    {
        inputFileStream >> value;
        count += value;
    }
    cout << count;
    return 0;
}

int getInteger(string prompt)
{
    if (prompt == "")
        prompt = "Input an integer here: ";
    int result;
    cout << prompt;
    cin >> result;
    return result;
}
/**
 * review questions 7
 */
void printProblem7()
{
    const double PI = 3.14159265358979323846;
    const double MYNUMBER = 0.0123456789;
    cout << setw(10) << 123 << endl;
    cout << setw(10) << left << 123 << endl;
    cout << setw(10) << right << 123 << endl; //setw宽度大于实际长度，default is right alignment
    cout << setfill('+') << setw(10) << 123 << endl;
    cout << setfill('+') << setw(10) << left << 123 << endl;
    cout << setfill('+') << setw(10) << right << 123 << endl;
    cout << "--------------------------------------------------" << endl;
    cout << PI << endl;                                  //精度位数、数值的表示方法均不可控、不可预知（eg科学计数法 or 普通计数）
    cout << setprecision(8) << PI << endl;               //表示方法不可控、不可预知
    cout << setprecision(8) << fixed << PI << endl;      //推荐使用。截断数位四舍五入
    cout << setprecision(8) << scientific << PI << endl; //推荐使用。截断数位四舍五入
    cout << "--------------------------------------------------" << endl;
    cout << MYNUMBER << endl;                                  //精度位数、数值的表示方法均不可控、不可预知（eg科学计数法 or 普通计数）
    cout << setprecision(8) << MYNUMBER << endl;               //表示方法不可控、不可预知
    cout << setprecision(8) << fixed << MYNUMBER << endl;      //截断数位四舍五入
    cout << setprecision(8) << scientific << MYNUMBER << endl; //截断数位四舍五入
    cout << "--------------------------------------------------" << endl;
    cout << setprecision(15) << fixed << PI << endl;
    cout << setprecision(6) << fixed << PI << endl;
    cout << setprecision(15) << scientific << PI << endl;
    cout << setprecision(6) << scientific << PI << endl;
    cout << setfill(' ') << setw(16) << setprecision(9) << fixed << PI << endl;
    cout << setw(8) << setfill('0') << setprecision(4) << fixed << PI << endl; // default setfill空格
    return;
}

/**
 * exercises problem 1
 */

void printTable()
{
    cout << setw(6) << "theta"
         << " |"
         << setw(11) << "sin(theta)"
         << " |"
         << setw(11) << "cos(theta)"
         << " |" << endl;
    cout << setw(7) << "-------+"
         << setw(12) << "------------+"
         << setw(12) << "------------+"
         << endl;
    for (double theta = -90; theta <= 90; theta += 15)
    {
        double newTheta = theta / 180 * M_PI; //#define _USE_MATH_DEFINES
        cout << setw(6) << fixed << setprecision(0) << theta << " |"
             << setw(11) << fixed << setprecision(7) << sin(newTheta) << " |"
             << setw(11) << fixed << setprecision(7) << cos(newTheta) << " |" << endl;
    }
    return;
}

/**
 * problem 3
 */
void error(string errorMessage)
{
    cerr << errorMessage << endl;
    exit(EXIT_FAILURE);
}

string longestLine(string filename)
{
    string result = "";
    string tmp = "";
    ifstream inputStream;
    inputStream.open(filename.c_str());
    if (inputStream.fail())
        error("Error occurs when open files!");
    while (getline(inputStream, tmp))
    {
        if (tmp.length() > result.length())
            result = tmp;
    }
    return result;
}

/**problem 4 */
int charsInLine(string line)
{
    return line.length();
}
int wordsInLine(string line)
{
    int wordCounts = 0;

    return wordCounts;
}

void count(ifstream &inputFileStream, string prompt)
{
    string filename;
    while (true)
    {
        int lineNumbers = 0;
        int wordNumbers = 0;
        int charNumbers = 0;
        if (prompt == "")
            prompt = "Input File name with extension name: ";
        cout << prompt;
        getline(cin, filename);
        inputFileStream.open(filename.c_str());
        if (!inputFileStream)
        {
            //error("Error occurs when open files!");
            cout << "Error occurs when open files, Check your input filename" << endl;
            continue;
        }
        string line;
        while (getline(inputFileStream, line))
        {
            lineNumbers++;
            wordNumbers += wordsInLine(line);
            charNumbers += charsInLine(line);
        }
        cout << "Total Line Numbers: " << lineNumbers << endl;
        cout << "Total Word Numbers: " << wordNumbers << endl;
        cout << "Total Character Numbers: " << charNumbers << endl;
        break;
    }
}

/**Can !inputFileStream.fail() cause duplicate read the last line? YES!
 * The right 'condition test' is to use .eof() instead of .fail(), when you want to test whether
 * filestream has read to the end.
 */
void duplicateRead(ifstream &inputFileStream, string prompt)
{
    string filename;
    if (prompt == "")
        prompt = "Input File name with extension name: ";
    cout << prompt;
    getline(cin, filename);
    inputFileStream.open(filename.c_str());
    if (!inputFileStream)
    {
        error("Error occurs when open files!");
    }
    string line;
    while (getline(inputFileStream, line))
    {
        cout << line << endl;
    }
    cout << "---------------Duplicate read the last line--------------------------" << endl;
    inputFileStream.close();
    inputFileStream.open(filename.c_str());
    while (inputFileStream) // always equals to "!inputFileStream.fail()" in conditional statement
    {
        getline(inputFileStream, line);
        cout << line << endl;
    }
    cout << "---------------fix the problem--------------------------" << endl;
    inputFileStream.close();
    inputFileStream.open(filename.c_str());
    while (!inputFileStream.eof()) // using .eof() to test whether loop should be ended.
    {
        getline(inputFileStream, line);
        cout << line << endl;
    }
}

void formattedStreamInput() //duplicate read the last line twice
{
    ifstream inputFileStream;
    int value;
    int count = 0;
    inputFileStream.open("numbers.txt");
    while (inputFileStream) // using this or .fail() in loop will cause 最后一行读2遍。
                            //Instead, we directly use  "inputFileStream >> value" or .eof() just like we use "getline()" and "get()" in loop.
    {
        inputFileStream >> value;
        count += value;
    }
    cout << count;
}