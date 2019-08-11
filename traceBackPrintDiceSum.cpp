#include <iostream>
#include <vector>
using namespace std;

const int MIN_DICE = 1;
const int MAX_DICE = 6;
void printDiceSum(int diceNumbers, int sum);
void printDiceSumHelper(int diceNumbers, int sum, int soFarDice, vector<int> &chosen);
void printVector(vector<int> &vec);
int countVector(vector<int> &vec);

int main()
{
    int n;
    cout << "Input numbers of dice N:";
    cin >> n;
    int sum;
    cout << "Input the number of sum:";
    cin >> sum;
    printDiceSum(n, sum);
    return 0;
}

void printDiceSum(int diceNumbers, int sum)
{
    vector<int> chosen;
    int soFarDice = 0;
    printDiceSumHelper(diceNumbers, sum, soFarDice, chosen);
}

void printDiceSumHelper(int diceNumbers, int sum, int soFarDice, vector<int> &chosen) //diceNumbers: the numbers of dice.
{
    //base case
    if (diceNumbers == 0)
    {
        printVector(chosen);
    }
    //recursive case
    else
    {
        //we  have several decisions, and for each decision we do things as follows
        for (int diceRoll = 1; diceRoll <= 6; diceRoll++)
        {
            soFarDice = countVector(chosen);
            if (sum >= soFarDice + diceRoll + MIN_DICE * (diceNumbers - 1) && sum <= soFarDice + diceRoll + MAX_DICE * (diceNumbers - 1)) //pruning to improve the efficiency
            {
                //choose one decision
                chosen.push_back(diceRoll);
                //represent the original problem by similar small scale problem(s), usally/always use recursive philosophy.
                printDiceSumHelper(diceNumbers - 1, sum, soFarDice, chosen);
                //un-choose i.e. backtrack
                chosen.erase(chosen.end() - 1);
            }
        }
    }
}

void printVector(vector<int> &vec)
{
    cout << "{";
    for (auto vecElement : vec)
    {
        cout << vecElement;
    }
    cout << "}" << endl;
}

int countVector(vector<int> &vec)
{
    int sum = 0;
    for (auto vecElement : vec)
    {
        sum += vecElement;
    }
    return sum;
}