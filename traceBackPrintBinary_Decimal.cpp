#include <iostream>
#include <sstream>

using namespace std;

void printBinary(int n);
void printBinaryHelper(int n, string prefix);
void printDecimal(int n);
void printDecimalHelper(int n, string prefix);
string intToString(int integerNumber);

int main()
{
    int n;
    cout << "Input numbers of digits N:";
    cin >> n;
    printBinary(n);
    printDecimal(n);
    return 0;
}

void printBinary(int n)
{
    string prefix = "";
    printBinaryHelper(n, prefix);
}

void printBinaryHelper(int n, string prefix)
{
    //base case
    if (n == 0)
    {
        cout << prefix << endl;
    }
    /**recursive case. The original problem(a larger scale problem) can be represented by similar smaller scale problem(s).
     * */
    else
    {
        printBinaryHelper(n - 1, prefix + "0");
        printBinaryHelper(n - 1, prefix + "1");
    }
}

void printDecimal(int n)
{
    string prefix = "";
    printDecimalHelper(n, prefix);
}

void printDecimalHelper(int n, string prefix)
{
    //base case
    if (n == 0)
    {
        cout << prefix << endl;
    }
    /**recursive case. The original problem(a larger scale problem) can be represented by similar smaller scale problem(s).
     * */
    else
    {
        for (int i = 0; i <= 9; i++)
            printDecimalHelper(n - 1, prefix + intToString(i));
    }
}

string intToString(int integerNumber)
{
    ostringstream myStringStream;
    myStringStream << integerNumber;
    return myStringStream.str();
}