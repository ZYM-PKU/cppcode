#include<bits/stdc++.h>
using namespace std;

int n,k;
char board[8][8]={0};
bool usedcol[8]={0};
int counting=0;


void dfs(int t,int row){
    if(t>k){counting++;return;}
    for(int i=row+1;i<n-k+t;i++){
        for(int j=0;j<n;j++){
            if(usedcol[j])continue;
            if(board[i][j]!='#')continue;
            usedcol[j]=true;
            dfs(t+1,i);
            usedcol[j]=false;
        }
    }
}




int main(){
    while(1){
        cin>>n>>k;
        if(n==-1&&k==-1)break;
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)cin>>board[i][j];
        dfs(1,-1);
        cout<<counting<<endl;
        counting=0;
        memset(board,0,sizeof(board));
        memset(usedcol,0,sizeof(usedcol));
    }
    return 0;
}