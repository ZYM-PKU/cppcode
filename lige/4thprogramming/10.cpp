#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
using namespace std;
struct road{
    int ai;
    int bi;
    int ci;
    int Pi;
    int Ri;
};
road roads[20];
int N,m;
int passcity[20]={0};
int sum=0;
int mincost=0xfffff;
void deepsearch(int city){
    passcity[city]++;//记录经历城市的次数
    if(city==N){
        mincost=min(mincost,sum);//到达终点，进行比较
    }
    else{
        for(int i=1;i<=m;i++){
        if(roads[i].ai==city&&passcity[city]<=5){//防止死循环
            if(passcity[roads[i].ci]){
                sum+=roads[i].Pi;
                deepsearch(roads[i].bi);//递归到下一个城市
                sum-=roads[i].Pi;//回溯
            }
            else{
                sum+=roads[i].Ri;
                deepsearch(roads[i].bi);
                sum-=roads[i].Ri;//回溯
            }
        }
    }
    }
     passcity[city]--;//回溯
     return;
}
int main(){
    cin>>N>>m;
    for(int i=1;i<=m;i++){
        cin>>roads[i].ai>>roads[i].bi>>roads[i].ci>>roads[i].Pi>>roads[i].Ri;
    }
    deepsearch(1);
    if(mincost==0xfffff)cout<<"impossible"<<endl;
    else cout<<mincost<<endl;
    return 0;
}