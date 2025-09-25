#include<iostream>
using namespace std;

void reverse(int arr[],int size){
    for(int i=0;i<=size/2;i++){
        int temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-i-1]= temp;
    }
}


int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,0};
    reverse(arr,10);

    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}