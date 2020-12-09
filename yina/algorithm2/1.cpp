#include<bits/stdc++.h>
using namespace std;
int main(){
    int map[5][5]={0};
    bool visited[5][5]={0};
    stack<pair<int,int>>track;
    int dx[4]={0,1,0,-1};
    int dy[4]={-1,0,1,0};
    for(int i=0;i<5;i++)
    for(int j=0;j<5;j++)cin>>map[i][j];
    track.push(make_pair(0,0));
    while(track.top()!=make_pair(4,4)){
        pair<int,int> temp=track.top();
        int x,y;
        bool good=false;
        for(int i=0;i<4;i++){
            x=temp.first+dx[i];
            y=temp.second+dy[i];
            if(x<0||y<0||x>4||y>4)continue;
            if(map[x][y])continue;
            if(visited[x][y])continue;
            
            track.push(make_pair(x,y));
            visited[x][y]=true;
            good=true;
            break;
            
        }
        if(!good)track.pop();
    }
    vector<pair<int,int>>tr;
    while(!track.empty()){
        tr.push_back(track.top());
        track.pop();
    }
    reverse(tr.begin(),tr.end());
    for(auto p:tr){
        cout<<"("<<p.first<<", "<<p.second<<")"<<endl;
    }


    return 0;
}