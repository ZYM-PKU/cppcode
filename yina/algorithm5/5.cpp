#include<bits/stdc++.h>
using namespace std;


int main(){
    int N,M,K;
    int a[105][2]={0};
    int dp[1005][505]={0};
    cin>>N>>M>>K;
    for(int i=1;i<=K;i++)cin>>a[i][0]>>a[i][1];
    for(int i=1;i<=K;i++){
        for(int j=N;j>=a[i][0];j--){
            for(int k=M;k>=a[i][1];k--){
                dp[j][k]=max(dp[j][k],dp[j-a[i][0]][k-a[i][1]]+1);
            }
        }

    }
    cout<<dp[N][M]<<" ";
    int maxlife=M;
    for(int i=0;i<=M;i++){
        if(dp[N][i]==dp[N][M]){
            maxlife=M-i;
            break;
        }
    }
    cout<<maxlife<<endl;

}