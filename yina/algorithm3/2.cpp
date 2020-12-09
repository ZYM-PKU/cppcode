#include<bits/stdc++.h>
using namespace std;


bool blocked[110][110]={0};
bool visited[110][110]={0};
int step[110][110]={0};

int dx[4][2]={{-2,-2},{-1,1},{2,2},{-1,1}};
int dy[4][2]={{-1,1},{2,2},{-1,1},{-2,-2}};
int bx[4]={-1,0,1,0};
int by[4]={0,1,0,-1};


int p,q;
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
            if(x+bx[i]<1||x+bx[i]>p)continue;
            if(y+by[i]<1||y+by[i]>q)continue;
            if(blocked[x+bx[i]][y+by[i]])continue;
            for(int j=0;j<2;j++){
                if(x+dx[i][j]<1||x+dx[i][j]>p)continue;
                if(y+dy[i][j]<1||y+dy[i][j]>q)continue;
                if(visited[x+dx[i][j]][y+dy[i][j]])continue;
                track.push(make_pair(x+dx[i][j],y+dy[i][j]));
                visited[x+dx[i][j]][y+dy[i][j]]=true;
                step[x+dx[i][j]][y+dy[i][j]]=step[x][y]+1;
            }

        }
        track.pop();
    }
    cout<<"can not reach!"<<endl;
    return;

}

int main(){

    int cases;
    cin>>cases;
    for(int c=0;c<cases;c++){
        memset(blocked,0,sizeof(blocked));
        memset(visited,0,sizeof(visited));
        memset(step,0,sizeof(step));
        cin>>p>>q;
        cin>>start.first>>start.second>>ending.first>>ending.second;
        int m;cin>>m;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            blocked[x][y]=true;
        }
        bfs();
    }
    return 0;
}
