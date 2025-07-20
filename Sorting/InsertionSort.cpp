#include <iostream>
using namespace std;

void InsertionSortIterative(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j>0 && arr[j-1]>arr[j])
        {
            if(arr[j]<arr[j-1]) swap(arr[j],arr[j-1]);
            j--;
        }
        
    }
}
void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {6,9,12,14,15,8,13};
    InsertionSortIterative(arr,7);
    printArr(arr,7);

    return 0;
}