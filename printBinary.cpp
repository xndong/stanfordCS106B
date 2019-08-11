#include <iostream>
#include <stack>

using namespace std;

void printBinary(int n, stack<int> &binaryStack);
int main()
{
    int n;
    stack<int> binaryStack;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        else
            printBinary(n, binaryStack);
        while (!binaryStack.empty())
        {
            cout << binaryStack.top();
            binaryStack.pop();
        }
        cout << endl;
    }
    return 0;
}

void printBinary(int n, stack<int> &binaryStack)
{
    if (n < 2)
        binaryStack.push(n);
    else
    {
        int remainder = n % 2;
        binaryStack.push(remainder);
        printBinary(n / 2, binaryStack);
    }
}