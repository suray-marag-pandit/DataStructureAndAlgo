#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int> &v){
    int n = v.size();
    for(int i=0;i<n;i++){
        bool flag = true;
        for(int j=0;j<n-i;j++){
            if(v[j]>v[j+1]) {
                  flag= false;
                swap(v[j+1],v[j]);
            }
        }   if(flag) return;
    }
}
int main(){
    vector<int> v = {5,4,3,2,1};
    bubbleSort(v);
    for(auto i:v){
        cout<<i<<" ";
    }

    return 0;
}