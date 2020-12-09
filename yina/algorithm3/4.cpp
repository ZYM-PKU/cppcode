#include<bits/stdc++.h>
using namespace std;



bool visited[100][100]={0};

int dx[3]={-1,0,0};
int dy[3]={0,1,-1};


int n;
int counting=0;


void dfs(int t,int x,int y){
    if(t>=n){counting++;return;}
    visited[x][y]=true;
    for(int i=0;i<3;i++){
        if(visited[x+dx[i]][y+dy[i]])continue;
        dfs(t+1,x+dx[i],y+dy[i]);
    }
    visited[x][y]=false;
}
int main(){

    cin>>n;
    dfs(0,50,50);
    cout<<counting<<endl;
    return 0;
}
