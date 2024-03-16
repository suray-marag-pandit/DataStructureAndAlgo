#include<iostream>
using namespace std;

int sumOfArray(int arr[],int size){
    if(size==0)
        return 0;
    if(size==1)
        return arr[0];
    else{ 
        int value = sumOfArray(arr+1,size-1);
        return (arr[0]+ value);
    }
}

int main(){
    int arr[]={2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    cout<<sumOfArray(arr,size);
    return 0;
}