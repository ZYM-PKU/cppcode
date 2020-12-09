/*#include<bits/stdc++.h>
using namespace std;


int N;
int counting=0;
vector<int>Array;


void dfs(int pos,int add){
    if(add==400){counting++;return;}
    if(pos>=N)return;
    for(int i=pos;i<N;i++){
        if(400-add<Array[i])return;
        dfs(i+1,add+Array[i]);
    }
}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        int x;cin>>x;Array.push_back(x);
    }
    sort(Array.begin(),Array.end());
    dfs(0,0);
    cout<<counting%10000<<endl;
    return 0;
}
*/

//动态规划
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n,a[210];
    cin>>n;
    int dp[420][210];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;++i){
        cin>>a[i];
        dp[0][i]=1;
    }
    dp[0][0]=1;
    for(int w=1;w<=400;++w){
        for(int k=1;k<=n;++k){
            dp[w][k]=dp[w][k-1]%10000;
            if(w-a[k]>=0){dp[w][k]+=dp[w-a[k]][k-1]%10000;dp[w][k]=dp[w][k]%10000;}
        }
    }
    cout<<(dp[400][n])<<endl;
    
    return 0;
}

