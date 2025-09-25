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
    return 0;
}

// | Algorithm      | Stable? | In-Place? |
// | -------------- | ------- | --------- |
// | Bubble Sort    | ✅ Yes   | ✅ Yes     |
// | Insertion Sort | ✅ Yes   | ✅ Yes     |
// | Merge Sort     | ✅ Yes   | ❌ No      |
// | Quick Sort     | ❌ No    | ✅ Yes     |
// | Heap Sort      | ❌ No    | ✅ Yes     |
// | Selection Sort | ❌ No    | ✅ Yes     |
