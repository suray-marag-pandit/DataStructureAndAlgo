#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    int n = 5; // Number of nodes in the graph.
    int arr[] = {7, 10, 4, 3, 20, 15};
    int k = 3;
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i < n; ++i)
    {
        if (pq.top() > arr[i])
        {   pq.pop();
            pq.push(arr[i]);
        }
    }

    cout << pq.top() << endl;

    return 0;
}
