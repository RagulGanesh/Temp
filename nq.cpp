#include<bits/stdc++.h>
using namespace std;
#define N 4
void printSolution(int board[N][N]){
        for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    cout<<"\n";
}
bool isSafe(int board[N][N],int row,int col){
    int i,j;
    for(i=0;i<col;i++){
        if(board[row][i]){
            return false;
        }
    }
    for(i=row,j=col;i>=0&&j>=0;i--,j--){
        if(board[i][j]){
            return false;
        }
    }
    for(i=row,j=col;i<N&&j>=0;i++,j--){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}
bool graphUtil(int board[N][N],int col){
    if(col>=N){
        printSolution(board);
        return true;
    }
    bool res=false;
    for(int i=0;i<N;i++){
        if(isSafe(board,i,col)==true){
            board[i][col]=1;
            res=graphUtil(board,col+1)||res;
            board[i][col]=0;
        }
    }
    return res;
}
void graph(){
    int board[N][N];
    memset(board,0,sizeof(board));
    if(graphUtil(board,0)==false){
        return;
    }
    return;
}
int main()
{
    graph();
    return 0;
}