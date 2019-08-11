#include <iostream>
#include <vector>
using namespace std;

void printDice(int diceNumbers);
void printDiceHelper(int diceNumbers, vector<int> &chosen);

int main()
{
    int n;
    cout << "Input numbers of dice N:";
    cin >> n;
    printDice(n);
    return 0;
}

void printDice(int diceNumbers)
{
    vector<int> chosen;
    printDiceHelper(diceNumbers, chosen);
}

void printDiceHelper(int diceNumbers, vector<int> &chosen) //diceNumbers: the numbers of dice.
{
    //base case
    if (diceNumbers == 0)
    {
        cout << "{";
        for (auto vecElement : chosen)
        {
            cout << vecElement;
        }
        cout << "}" << endl;
    }
    //recursive case
    else
    {
        //we  have several decisions/choices, and for each decision/choice we do things as follows
        for (int diceRoll = 1; diceRoll <= 6; diceRoll++)
        {
            //choose one decision/choice
            chosen.push_back(diceRoll);
            //Explore choices which follows our current chosen choice/decision, of course we should use recursive philosophy. We represent the original problem by similar small scale problem(s).
            printDiceHelper(diceNumbers - 1, chosen);
            //un-choose i.e. backtrack
            chosen.erase(chosen.end() - 1);
        }
    }
}