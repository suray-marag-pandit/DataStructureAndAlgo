#include<iostream>
using namespace std;

bool searchL(int arr[],int size,int target){
    if(size==0)
        return false;

    if(arr[0]==target)
        return true;

    
    return searchL(arr+1,size-1,target);
    
}
int main(){
    int arr[] = {1,2,4,5,9,8,7};
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<searchL(arr+1,size-1,10);
    return 0;
}