#include <iostream>
using namespace std;

void bubbleSortIterative(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        bool flag =  true;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]); 
                flag = false;
            }
        }
        if(flag) break;
    }
}

void recursionBubbleSort(int arr[],int size){
    if(size==1) return;

    bool flag = true;
    for(int i=0;i<size-1;i++){
        if(arr[i]>arr[i+1]) {
            swap(arr[i],arr[i+1]);
        flag = false;
        }
    }
    if(flag) return;
    cout<<"recursion happened"<<endl;

    recursionBubbleSort(arr,size-1);

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
    //  int arr[7] = {7, 6, 5, 4, 3, 2, 1};
     int arr[7] = {11,12,13,14,15,16,17};
    // selectionSort(arr, 7);

    // bubbleSortIterative(arr,7);
    recursionBubbleSort(arr,7);
    printArr(arr, 7);
    return 0;
}