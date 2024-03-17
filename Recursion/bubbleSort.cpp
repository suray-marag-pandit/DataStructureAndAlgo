#include<iostream>
using namespace std;

void BubbleSort(int *arr,int size){
    if(size==0 or size==1)
        return;

    for(int i=0;i<size-1;i++){
        if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
    }
    BubbleSort(arr,size-1);
}

void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int main(){
    int arr[]={5,8,4,3,2,1};
    BubbleSort(arr,6);
    print(arr,6);

    return 0;
}