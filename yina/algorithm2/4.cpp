#include<bits/stdc++.h>
using namespace std;

int MAX=0;
int n;
int a[3]={0};
void dfs(int t){
    if(t>2){
        if(a[0]+a[1]+a[2]>MAX)MAX=a[0]+a[1]+a[2];
        return;
    }
    for(int i=n;i>=0;i--){
        if(t==0){
            if(i+2*n<=MAX)break;
            a[t]=i;
            dfs(t+1);
        }
        else if(t==1){
            if(i+n+a[0]<=MAX)break;
            if((a[0]+i)%2==0){
                a[t]=i;
                dfs(t+1);
            }
        }
        else{
            if(i+a[0]+a[1]<=MAX)break;
            if((a[1]+i)%3==0&&(a[0]+a[1]+i)%5==0){
                a[t]=i;
                dfs(t+1);
            }
        }

    }


}
int main(){
    cin>>n;
    dfs(0);
    cout<<MAX<<endl;
    return 0;
}