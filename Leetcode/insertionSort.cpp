#include<iostream>
#include<vector>
using namespace std;
void Insertion(vector<int> &v){
    int n = v.size();
    for(int i = 1; i < n; i++){
        int temp = v[i];
        int j = i - 1;

        // Shift elements to the right
        while(j >= 0 && v[j] > temp){
            v[j+1] = v[j];
            j--;
        }

        // Place temp at correct position
        v[j+1] = temp;
    }
}

int main(){
    vector<int> v = {5, 4, 3, 2, 1};
    Insertion(v);
    for(auto i : v){
        cout << i << " ";
    }

    return 0;
}
