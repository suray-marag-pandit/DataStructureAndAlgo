#include<iostream>
using namespace std;

bool searchLinear(int arr[],int size, int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            cout<< i<<endl;
            return true;

        }
    }
    return false;
}

int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(int);

    searchLinear(arr,size,5);
    searchLinear(arr,size,9);
    return 0;
}