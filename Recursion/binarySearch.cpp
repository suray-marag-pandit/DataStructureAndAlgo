#include<iostream>
using namespace std;

bool binarySearch(int arr[],int start,int end,int target){

    if(start > end){
        return false;
    }

    int mid = start+(end-start)/2;

    if(arr[mid]==target)
        return true;
    else if(arr[mid]>target)
        end = mid-1;
    else    
        start = mid+1;


    return binarySearch(arr,start,end,target);
}
int main(){
    int arr[] ={1,2,3,4,5,6,7,8,9};
    int start= 0;
    int end = sizeof(arr)/sizeof(arr[0])-1;
    int target = 5;
    cout<<binarySearch(arr,start,end-1,target);

    return 0;
}