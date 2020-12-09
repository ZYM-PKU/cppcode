#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
int maxbow=0;
int N,F,D;
struct bow{
    int fnum;
    int dnum;
    int food[100];
    int drink[100];
}bows[150];
bool usedfood[150]={0};
bool useddrink[150]={0};
void allocate(int n,int count){//给第n个奶牛分配东西
    if(n==N){
        int judge=false;
        for(int i=1;i<=bows[n].fnum;i++){
            if(judge)break;
            for(int j=1;j<bows[n].dnum;j++){
                if(!usedfood[i]&&!useddrink[j]){
                    count++;
                    judge=true;
                    break;
                }
            }
        }
        maxbow=max(maxbow,count);
        return;
    }
    else{
        for(int i=1;i<=bows[n].fnum;i++){
            for(int j=1;j<bows[n].dnum;j++){
                if(!usedfood[i]&&!useddrink[j]){
                    usedfood[i]=true;
                    useddrink[j]=true;
                    allocate(n+1,count+1);
                    usedfood[i]=false;
                    useddrink[j]=false;
                }
            }
        }
        allocate(n+1,count+1);
    }


}
int main(){
    int N,F,D;
    cin>>N>>F>>D;
    for(int x=1;x<=N;x++){
        cin>>bows[x].fnum>>bows[x].dnum;
        for(int i=1;i<=bows[x].fnum;i++)cin>>bows[x].food[i];
        for(int i=1;i<=bows[x].dnum;i++)cin>>bows[x].drink[i];
    }
    allocate(1,0);
    cout<<maxbow<<endl;
    return 0;
}