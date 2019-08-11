#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int boardSize = 8;
void eightQueens(vector<vector<char>> &board);
void eightQueensHelper(vector<vector<char>> &board, int col);
void printTwoDimensionVec(vector<vector<char>> &twoDimensionVector);
void placeQueen(vector<vector<char>> &twoDimensionVector, int row, int col);
void removeQueen(vector<vector<char>> &twoDimensionVector, int row, int col);
bool isSafe(vector<vector<char>> &twoDimensionVector, int row, int col);

int queens_arrangement = 0;

int main()
{
    vector<vector<char>> board(boardSize, vector<char>(boardSize, '-'));
    eightQueens(board);
    cout << "Total Queens Arrangement: " << queens_arrangement << endl;
    return 0;
}

void eightQueens(vector<vector<char>> &board)
{
    int col = 0;
    eightQueensHelper(board, col);
}

void eightQueensHelper(vector<vector<char>> &board, int col)
{
    if (col >= 8)
    {
        printTwoDimensionVec(board);
        queens_arrangement++;
    }
    else
    {
        for (int row = 0; row < 8; row++)
        {
            if (isSafe(board, row, col))
            {
                placeQueen(board, row, col);
                eightQueensHelper(board, col + 1);
                removeQueen(board, row, col);
            }
        }
    }
}

void printTwoDimensionVec(vector<vector<char>> &twoDimensionVector)
{
    for (auto row : twoDimensionVector)
    {
        for (auto rowElement : row)
            cout << rowElement << " ";
        cout << endl;
    }
    cout << endl;
}

void placeQueen(vector<vector<char>> &twoDimensionVector, int row, int col)
{
    twoDimensionVector[row][col] = 'Q';
}

void removeQueen(vector<vector<char>> &twoDimensionVector, int row, int col)
{
    twoDimensionVector[row][col] = '-';
}

bool isSafe(vector<vector<char>> &twoDimensionVector, int row, int col)
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (twoDimensionVector[i][col] == 'Q' || twoDimensionVector[row][j] == 'Q')
                return false;
            if (abs(i - row) == abs(j - col) && twoDimensionVector[i][j] == 'Q')
                return false;
        }
    }
    return true;
}