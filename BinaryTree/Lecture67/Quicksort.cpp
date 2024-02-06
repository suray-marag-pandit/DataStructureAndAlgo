#include<stdio.h>


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);

        printf("\nleft subarray: [");
        for(int i=0;i<pivotIndex;i++ ){
            printf("%d,",arr[i]);
        }
        printf("]\n");

        printf("%d \t",arr[pivotIndex]);
        
        printf("\nright subarray: [");
        for(int j=pivotIndex+1;j<high;j++ ){
            printf("%d,",arr[j]);
        }
        printf("]\n ---------------------------------");


        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}


int main()
{
    int arr[] = {9,8,6,5,4,7,2,1};

    quickSort(arr,0,7);


    printf("\n");
    for(int i =0;i<8;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
