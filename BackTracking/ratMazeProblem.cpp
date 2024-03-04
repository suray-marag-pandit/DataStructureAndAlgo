#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int x, int y, int n, vector<vector<int>> arr, vector<vector<bool>> visited)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && arr[x][y] == 1 && visited[x][y] != true)
        return true;
    else
        return false;
}

void solve(int x, int y, int n, vector<vector<int>> arr, vector<string> &ans, vector<vector<bool>> &visited, string path)
{
    // base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = true;
    // down
    if (isSafe(x + 1, y, n, arr, visited))
    {
        solve(x + 1, y, n, arr, ans, visited, path +'D');
    }
    // left
    if (isSafe(x, y - 1, n, arr, visited))
    {
        solve(x, y - 1, n, arr, ans, visited, path + 'L');
    }
    // right
    if (isSafe(x, y + 1, n, arr, visited))
    {
        solve(x, y + 1, n, arr, ans, visited, path +'R');
    }
    // up
    if (isSafe(x - 1, y, n, arr, visited))
    {
        solve(x - 1, y, n, arr, ans, visited, path + 'U');
    }
    visited[x][y] = 0;
}

// vector<vector<bool>> visited(n, vector<bool>(n,0));

int main()
{

    int n = 5;
    vector<vector<int>> arr = {
        {1, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 1}
    };

    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    string path = "";

    solve(0, 0, n, arr, ans, visited, path);

    for (auto i : ans)
    {
        cout<<i<<endl;
    }
    
    return 0;
}
