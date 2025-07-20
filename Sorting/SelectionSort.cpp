#include <iostream>
using namespace std;

void selectionSort(int arr[], int size)
{
    if (size == 1)
        return;

    int smallest = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[0])
            swap(arr[0], arr[i]);
    }

    selectionSort(arr + 1, size - 1);
}

void selectionSortIterative(int arr[],int size){
    for(int i=0;i<size-1;i++){
        int pointer = i;
        for (int j = i+1; j < size; j++)
        {
            if(arr[j]<arr[i]) swap(arr[i],arr[j]);
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
    int arr[7] = {7, 6, 5, 4, 3, 2, 1};
    // selectionSort(arr, 7);

    selectionSortIterative(arr,7);
    printArr(arr, 7);

    return 0;
}