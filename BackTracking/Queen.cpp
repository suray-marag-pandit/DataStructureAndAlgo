#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int row,int col, vector<vector<int>> board,int n){
    for(int i = 0 ;i<col;i++){
        if(board[row][i]==1)
        return false;
    }

    for(int i = row,j=col;i>0 && j>0 ;i--,j--){
        if(board[i][j]==1)
            return false;
    }
    
    for(int i = row,j=col;i < n && j>0 ;i++,j--){
        if(board[i][j]==1)
            return false;
    }
    
    return true;
}


bool solve(int col, vector<vector<int>> &board,int n){
    if(col==n){
        return true;
    }

    for(int i = 0; i < n; i++ ){
        if(isSafe(i,col,board,n)){

            board[i][col]=1;
            if(solve(col+1,board,n)) return true;
            board[i][col]=0;
        }
    }
    return false;
}

void print(vector<vector<int>> board,int n){
    for(int i= 0;i<n;i++){
        for (int j = 0; j < n; j++)
        {
            if(board[i][j]==1) cout<<"Q";
            else cout<<"-";
        }cout<<endl;
        
    }
}


int main(int argc, char const *argv[])
{
    int n = 4;

    vector<vector<int>> board(n, vector<int>(n, 0));

    solve(0, board, n);

    print(board, n);

    return 0;
}
