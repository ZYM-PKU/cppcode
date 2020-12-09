#include<bits/stdc++.h>
using namespace std;

int main(){
    int dp[100]={0};
    dp[0]=dp[1]=1;
    for(int i=2;i<=20;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[20]<<endl;

    return 0;
}