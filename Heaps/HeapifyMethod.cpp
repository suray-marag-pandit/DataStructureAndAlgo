#include <iostream>
using namespace std;

void heapify(int arr[], int n)
{
    for (int i = n / 2; i > 0; i--)
    {
        int leftchild = 2 * i;
        int rightchild = 2 * i + 1;
        int largest = i;

        if (leftchild < n && arr[leftchild] > arr[largest])
            largest = leftchild;

        if (rightchild < n && arr[rightchild] > arr[largest])
            largest = rightchild;

        if (largest != i)
            swap(arr[i], arr[largest]);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {0, 54, 53, 55, 52, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapify(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
