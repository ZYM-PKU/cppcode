#include<bits/stdc++.h>
using namespace std;






int value[150]={0};
int dp[150][150]={0};

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>value[i];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int l=1;l<=j;l++){
                dp[i][j]=max(dp[i][j],dp[i-1][j-l]+value[l]);
            }
        }
    }
    cout<<dp[m][n]<<endl;
}