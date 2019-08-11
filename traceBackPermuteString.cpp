#include <iostream>
#include <string>

using namespace std;

void permuteString(string s);
void permuteStringHelper(string s, string chosen);

int main()
{
    while (true)
    {
        string s;
        cin >> s;
        if (s == "0")
            break;
        permuteString(s);
    }
    return 0;
}

void permuteString(string s)
{
    string chosen = "";
    permuteStringHelper(s, chosen);
}

void permuteStringHelper(string s, string chosen)
{
    if (s.empty())
    {
        cout << chosen << endl;
    }
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            //choose
            char c = s[i];
            chosen += c;
            //explore:for every decision(对于每一次决策or每一个choice)，we explore choices following that decision/choices, Of cource, we need to do this by using recurse.
            permuteStringHelper(s.erase(i, 1), chosen);
            //unchoose
            chosen.pop_back();
            s.insert(i, 1, c);
        }
    }
}