#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
using namespace std;
struct delta{
    int lpos;
    int rpos;
    int del;
}d[5500];
bool cmp(delta a,delta b){
    return a.del<b.del;
}
bool used[5500]={0};
int main(){
    int n,k;
    int count=0;
    int chop[5500]={0};
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>chop[i];
    }
    sort(chop,chop+n);//升序排列
    for(int i=0;i<n-1;i++){
        d[i].del=(chop[i+1]-chop[i])*(chop[i+1]-chop[i]);//计算相邻差
        d[i].lpos=i;//记录较长筷子的位置
        d[i].rpos=i+1;
    }
    sort(d,d+n-1,cmp);//对间隔排序
    int sum=0;
    int t=0;
    while(count<k){
        bool result=false;
        if((!used[d[t].lpos])&&(!used[d[t].rpos])){
            for(int i=d[t].rpos+1;i<n;i++){
                if(!used[i]){
                    result=true;
                    used[i]=true;
                    used[d[t].lpos]=used[d[t].rpos]=true;
                    count++;
                    sum+=d[t].del;
                    t++;
                    break;
                }
            }
        }
        if(!result)t++;
    }
    cout<<sum<<endl;
    return 0;
}
