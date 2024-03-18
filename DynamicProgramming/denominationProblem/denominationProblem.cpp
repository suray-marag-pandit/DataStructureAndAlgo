#include<iostream>
#include<vector>
using namespace std;


int denomination(vector<int> arr,int x){
    //base case
    if(x==0)
        return 0;
    if(x < 0)
        return INT_MAX;
    
    int mini = INT_MAX;
    
    for(int i = 0; i < arr.size(); i++){
        int ans = denomination(arr,x-arr[i]);
        if(ans!=INT_MAX)
            mini = min(ans+1,mini);
    }

    return mini;
}


int denominationMem(vector<int> arr,int x,vector<int> &dp){
    //base case
    if(x==0)
        return 0;
    if(x < 0)
        return INT_MAX;
    
    if(dp[x]!=-1)
        return dp[x];


    int mini = INT_MAX;
    
    for(int i = 0; i < arr.size(); i++){
        int ans = denominationMem(arr,x-arr[i],dp);
        if(ans!=INT_MAX)
            mini = min(ans+1,mini);
    }

    dp[x]=mini;

    return mini;
}
int main(){
    vector<int> arr ={9,5,6,1};
    int x = 11;
    vector<int> dp(x + 1,-1);
    cout<<denomination(arr,x)<<endl;
    cout<<denominationMem(arr,x,dp);


    return 0;
}