#include<iostream>
using namespace std;

void printArray(int arr[],int size){
    arr[0]=10;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[10]= {1};

    printArray(arr,10);
    cout<<arr[0]<<endl;
    cout<<sizeof(arr)/sizeof(int)<<endl;
    return 0;
}