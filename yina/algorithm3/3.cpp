#include<bits/stdc++.h>
using namespace std;


char board[1100][1100]={0};
bool visited[1100][1100]={0};
int step[1100][1100]={0};

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};


int m,n;

pair<int,int>start,ending;




void bfs(){
    queue<pair<int,int>> track;
    track.push(start);
    visited[start.first][start.second]=true;
    while(!track.empty()){
        int x=track.front().first;
        int y=track.front().second;
        if(x==ending.first&&y==ending.second){
            cout<<step[x][y]<<endl;
            return;
        }
        for(int i=0;i<4;i++){
            if(x+dx[i]<0||x+dx[i]>=m)continue;
            if(y+dy[i]<0||y+dy[i]>=n)continue;
            if(visited[x+dx[i]][y+dy[i]])continue;
            if(board[x+dx[i]][y+dy[i]]=='1')continue;
            track.push(make_pair(x+dx[i],y+dy[i]));
            visited[x+dx[i]][y+dy[i]]=true;
            step[x+dx[i]][y+dy[i]]=step[x][y]+1;
        }
        track.pop();
    }
    cout<<0<<endl;
    return;

}

int main(){

    cin>>m>>n;
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
        cin>>board[i][j];
        if(board[i][j]=='*')start=make_pair(i,j);
        if(board[i][j]=='+')ending=make_pair(i,j);
    }
    bfs();

    return 0;
}
