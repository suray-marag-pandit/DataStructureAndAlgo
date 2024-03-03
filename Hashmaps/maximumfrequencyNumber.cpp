#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    
    int arr[] = {-5, 20, 15, 20, 10, 30, 35, 10, 45, 50, 0, 50, -2, -8, 5};
    int  n = sizeof(arr) / sizeof(arr[0]);
    unordered_map<int, int> count;

    int largest = INT_MIN;
    int current;
    for (auto i =0 ; i < n; i++){
        count[arr[i]]++;
        largest = max(largest,count[arr[i]]);
    }

    for(auto i : count ){
        if(i.second==largest){
            cout<<i.first<<endl;
            break;
        }
    }

        return 0;
}
