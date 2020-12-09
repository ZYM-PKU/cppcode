#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
using namespace std;
struct pean{
    int row;
    int col;
    int count;
};

int main(){
    int times;
    cin>>times;
    for(int x=1;x<=times;x++){
        int atlas[25][25]={0};
        int t=1;//记录有花生的节点个数
        int sum=0;
        int steps=0;
        pean peans[500],temp;
        int m,n,k;
        cin>>m>>n>>k;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>atlas[i][j];
            if(atlas[i][j]){
                peans[t].row=i;
                peans[t].col=j;
                peans[t].count=atlas[i][j];//记载有效信息
                t++;
            }
        }
    }
    for(int i=1;i<t-1;i++){
        for(int j=1;j<t-i;j++){
             if(peans[j].count<peans[j+1].count){
                 temp=peans[j];peans[j]=peans[j+1];peans[j+1]=temp;//倒序排列
             }
        }
    }
    for(int i=1;i<t;i++){
        if(i==1){
            steps=2*peans[1].row+1;
        }
        else{
            steps=steps-peans[i-1].row+abs(peans[i].row-peans[i-1].row)+abs(peans[i].col-peans[i-1].col)+1+peans[i].row;
        }
        if(steps<=k){
             sum+=peans[i].count;
        }
        else{
            break;
        }
    }
    cout<<sum<<endl;
    }
    return 0;
}