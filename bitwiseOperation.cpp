#include<iostream>
using namespace std;

int main(){
    
    int ans=0;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<(ans^i)<<endl;
        ans^=i;
    }
    cout<<ans;
    return 0;
}