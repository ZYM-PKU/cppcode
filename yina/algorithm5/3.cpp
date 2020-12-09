#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int n,a[21];
    cin>>n;
    int dp[42][21];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;++i){
        cin>>a[i];
        dp[0][i]=1;
    }
    dp[0][0]=1;
    for(int w=1;w<=40;++w){
        for(int k=1;k<=n;++k){
            dp[w][k]=dp[w][k-1];
            if(w-a[k]>=0){dp[w][k]+=dp[w-a[k]][k-1];dp[w][k]=dp[w][k];}
        }
    }
    cout<<(dp[40][n])<<endl;
    
    return 0;
}

