#include<iostream>
using namespace std;

bool isSorted(int arr[],int size){
    if(size==0 or size ==1)
        return true;
    if(arr[0]>arr[1])
        return false;
    else{
        bool ans =  isSorted(arr+1,--size);
        return ans;
    }
}

int main(){
    int arr[]={1,2,3,4,5,6};
    // int arr[]= {}; 
    // int arr[]= {10};
    // int arr[] = {1,2,4,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<isSorted(arr,size);
    return 0;
}