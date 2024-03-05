#include <iostream>
#include <vector>
using namespace std;

void print(vector<vector<int>> board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                cout << "Q";
            }
            else
                cout << "-";
        }
        cout << endl;
    }
}

bool isSafe(int col, int row, vector<vector<int>> board, int n)
{

    for (int i = 0; i < col; i++)
    {
        if (board[row][i] == 1)
            return false;
    }

    for (int x = row, y = col; x >= 0 && y >= 0; x--, y--)
    {
        if (board[x][y] == 1)
            return false;
    }

    for (int x = row, y = col; x < n && y >= 0; x++, y--)
    {
        if (board[x][y] == 1)
            return false;
    }

    return true;
}
bool solve(int col, vector<vector<int>> &board, int n)
{

    if (col == n)
    {
        return true;
    }

    for (int i = 0; i < n; i++)
    {

        if (isSafe(col, i, board, n))
        {
            board[i][col] = 1;
            if (solve(col + 1, board, n))
                return true;
            board[i][col] = 0;
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    int n = 11;

    vector<vector<int>> board(n, vector<int>(n, 0));

    solve(0, board, n);

    print(board, n);

    return 0;
}
