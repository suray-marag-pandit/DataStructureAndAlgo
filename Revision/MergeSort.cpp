#include <iostream>
using namespace std;

void merge(int arr[], int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;
    int *first = new int[len1];
    int *second = new int[len2];

    // copy value
    int k = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[k++];
    }

    k = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[k++];
    }

    // merge
    int index = 0;
    int index2 = 0;
    int mainArrayIndex = s;

    while (index < len1 && index2 < len2)
    {
        if (first[index] < second[index2])
        {
            arr[mainArrayIndex++] = first[index++];
        }
        else
        {
            arr[mainArrayIndex] = second[index2++];
        }

        while (index < len1)
        {
            arr[mainArrayIndex++] = first[index++];
        }
        while (index2 < len2)
        {
            arr[mainArrayIndex] = second[index2++];
        }
    }
}

void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    merge(arr, s, e);
}

int main()
{
    int arr[] = {1, 2, 4, 5, 7, 1, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, 7);
     for(int i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}