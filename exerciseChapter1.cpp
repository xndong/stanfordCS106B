#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <cmath>
#include <math.h>
using namespace std;

int main()
{

    /*
     *problem 1
     */
    float temperature;
    cout << "Please input a temperature in degrees Celsius:";
    cin >> temperature;
    cout << "The temperature in degrees Fahrenheit is:" << 9 / 5 * temperature + 32 << endl;
    /*
     *problem 2
     */
    const float distanceRateOne = 0.0254;
    const int distanceRateTwo = 12;
    float meters;
    cout << "Please input the distance in meters:";
    cin >> meters;
    float inch = meters / distanceRateOne;
    float foot = inch / distanceRateTwo;
    cout << "Distance in meters " << meters << " is " << inch << " inches and " << foot << " foots." << endl;
    /*
     *problem3
     */
    int number, result = 0;
    cout << "Input Guassian's number:";
    cin >> number;
    for (int i = 0; i <= number; i++)
    {
        result += i;
    }
    cout << "The result is: " << result << endl;
    /*
     *problem 4
     *we will define a function to avoid local variables
     *function is  important because of decompositon and abstract
    */
    int firtNumOdd(int n);
    int numberN;
    cout << "Input an integer N: ";
    cin >> numberN;
    cout << firtNumOdd(numberN) << endl;
    /*
     *problem 8
     */
    int aNumber;
    int reverseInteger(int number);
    cout << "Input a number:";
    cin >> aNumber;
    cout << reverseInteger(aNumber) << endl;

    /*
     *problem 10
     */
    int aNumberProblem10;
    int problem10Solver(int number);
    cout << "Input a number:";
    cin >> aNumberProblem10;
    problem10Solver(aNumberProblem10);

    /**
     * problem 11
     */
    double computePi(int totalTerms);
    int totalTimes;
    cout << "Input a number to compute PI:";
    cin >> totalTimes;
    cout << computePi(totalTimes) << endl;

    return 0;
}

/**
 * problem 11 function
 */
double computePi(int totalTimes)
{
    double pi = 0;
    for (int i = 1; i <= totalTimes; i++)
        pi += pow(-1, i - 1) * 1 / (2 * i - 1);
    return 4 * pi;
}

/**
 * function definition problem 10
 */
int problem10Solver(int number)
{
    while (true)
    {
        if (number == 1)
            break;
        else if (number % 2 == 0)
        {
            cout << number << " is even, so I divided by 2 and get ";
            number /= 2;
            cout << number << endl;
        }
        else if (number % 2 == 1)
        {
            cout << number << " is even, so I multiply by 3 and add 1 to get ";
            number = number * 3 + 1;
            cout << number << endl;
        }
    }
    return 0;
}

/*
 * function definition
 */
int firtNumOdd(int n)
{
    int result = 0;
    for (int i = 1; i <= n; i++)
        result = result + 2 * i - 1;
    return result;
}

/**
 * function definition problem 7
 */
int reverseInteger(int number)
{
    int reverseResult = 0;
    stack<int> remainder;
    while (number > 0)
    {
        remainder.push(number % 10);
        number = number / 10;
    }
    for (int i = 0; !remainder.empty(); i++)
    {
        int addOperatorOne = remainder.top();
        remainder.pop();
        double addOperatorTwo = pow(10, i);
        reverseResult = reverseResult + addOperatorOne * int(addOperatorTwo);
    }
    return reverseResult;
}
