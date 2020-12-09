#include<bits/stdc++.h>
using namespace std;



#define MAX 101
int main(){
    int a[MAX][MAX]={0};
    int maxsum[MAX][MAX]={0};
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
            if(i==n)maxsum[i][j]=a[i][j];
        }
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            maxsum[i][j]=max(maxsum[i+1][j],maxsum[i+1][j+1])+a[i][j];
        }
    }
    cout<<maxsum[1][1]<<endl;
    return 0;
}