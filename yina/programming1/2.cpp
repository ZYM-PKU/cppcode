#include<bits/stdc++.h>
using namespace std;

int calfactorial(int n){
    long long result=1;
    for(int i=n;i>=1;i--)result*=i;
    return result;
}
int main(){
    long long total,part;
    char choice;
    cin>>total>>part>>choice;
    long long results[1000][1000]={0};
    for(int i=0;i<500;i++){
        for(int j=0;j<=i;j++){
            if(j==0)results[i][j]=1;
            else results[i][j]=results[i-1][j-1]+results[i-1][j];
        }
    }
    if(choice=='C')cout<<results[total][part];
    else cout<<results[total][part]*calfactorial(part);
    return 0;
}