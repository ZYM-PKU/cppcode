#include <bits/stdc++.h>
using namespace std;

int N,M;

double dis(pair<int,int>p1,pair<int,int>p2){
    return sqrt(pow((p1.first-p2.first),2)+pow((p1.second-p2.second),2));
}

double dismap[200][200]={0};
vector<pair<int,int>>dotset;


double dijistla(int s,int t){
    double result;
    double dist[N];
    for(int i=0;i<N;i++){
        dist[i]=dismap[s][i];
    }
    int prev=s;
    int temp=s;
    double min_value;
    bool solved[N]={0};
    solved[s]=true;
    while(1){
        min_value=0xffffff;
        for(int i=0;i<N;i++){
            if(dist[i]<min_value&& !solved[i]){
                temp=i;
                min_value = dist[i];
            }
        }
        solved[temp]=true;
        if(temp==t)return min_value;
        for(int i=0;i<N;i++){
            dist[i]=min(dist[i],dist[prev]+dismap[prev][i]);
        }
        prev=temp;
    }    
}


int main() {
    
    cin>>N;
    for (int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        dotset.push_back(make_pair(x,y));
    }
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
    {
        dismap[i][j]=0xffffff;
        if(i==j)dismap[i][j]=0;
    }
    cin>>M;
    for (int i=0;i<M;i++){
        int p1,p2;
        cin>>p1>>p2;
        dismap[p1-1][p2-1]=dismap[p2-1][p1-1]=dis(dotset[p1-1],dotset[p2-1]);
    }
    int s,t;
    cin>>s>>t;s--;t--;
    cout<<fixed<<setprecision(2)<<dijistla(s,t);
    return 0;
}