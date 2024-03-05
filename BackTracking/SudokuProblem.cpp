#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row, int col, int number, vector<vector<int>> board, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == number)
            return false;
        if (board[i][col] == number)
            return false;

        if (board [3*(row/ 3) + i/3][3*(col/3) + i%3]==number)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
            {
                for (int number = 1; number <=9; number++)
                {
                    if (isSafe(i, j, number, board, n))
                    {
                        board[i][j] = number;
                        if (solve(board, n))
                            return true;
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> board = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    solve(board, 9);

    int n =9;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<board[i][j]<<" ";
        }cout<<endl;
        
    }
    
    return 0;
}