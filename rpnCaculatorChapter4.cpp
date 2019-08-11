#include <iostream>
#include <stack>
#include <cctype>
#include <sstream>
#include <cstdlib>

using namespace std;

void error(string msg);
void helpCommand();
double stringToReal(string line);
void applyOperator(char op, stack<double> &operandStack);

int main()
{
    cout << "RPN Caculator Simulation, type 'H' for help" << endl;
    stack<double> operandStack;
    while (true)
    {
        string operand;
        getline(cin, operand);
        if (operand.length() == 0)
            operand = "Q";
        char ch = toupper(operand[0]);
        switch (ch)
        {
        case 'Q':
            break;
        case 'H':
            helpCommand();
            continue;
        case 'C':
            //operandStack.clear();
            continue;
        default:
        {
            if (isdigit(ch))
                operandStack.push(stringToReal(operand));
            else
                applyOperator(ch, operandStack);
        }
        }
    }
    return 0;
}

void applyOperator(char op, stack<double> &operandStack)
{
    double result;
    double rhs = operandStack.top();
    operandStack.pop();
    double lhs = operandStack.top();
    operandStack.pop();
    switch (op)
    {
    case '+':
        result = lhs + rhs;
        break;
    case '-':
        result = lhs - rhs;
        break;
    case '*':
        result = lhs * rhs;
        break;
    case '/':
        result = lhs / rhs;
        break;
    default:
        error("Illegal operator!");
    }
    cout << result << endl;
    operandStack.push(result);
}

void error(string msg)
{
    cout << msg << endl;
    exit(EXIT_FAILURE);
}
void helpCommand()
{
    cout << "Q---quit the program" << endl;
    cout << "H---show this help doc" << endl;
    cout << "C---clear the caculator stack" << endl;
}

double stringToReal(string line)
{
    double result;
    istringstream inputStringStream(line);
    inputStringStream >> result;
    return result;
}