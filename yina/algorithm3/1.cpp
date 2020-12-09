#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    queue<int> line;
    bool visited[100001]={0};
    int step[100001]={0};
    line.push(N);
    visited[N]=true;
    while(!line.empty()){
        int x=line.front();
        if(x==K){
            cout<<step[x]<<endl;
            break;
        }
        if(x-1>=0&&!visited[x-1]){visited[x-1]=true;line.push(x-1);step[x-1]=step[x]+1;}
        if(x+1<=100000&&!visited[x+1]){visited[x+1]=true;line.push(x+1);step[x+1]=step[x]+1;}
        if(2*x<=100000&&!visited[x*2]){visited[x*2]=true;line.push(2*x);step[x*2]=step[x]+1;}
        line.pop();
    }


    return 0;
}