#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int> & arr){
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}
int main(){
    vector<int> arr = {64, 25, 12, 22, 11};
    selectionSort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}