#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        int tspeed[1100]={0};
        int qspeed[1100]={0};
        int sum=0;
        if(n==0)break;
        for(int i=0;i<n;i++){
            cin>>tspeed[i];
        }
        for(int i=0;i<n;i++){
            cin>>qspeed[i];
        }
        sort(tspeed,tspeed+n);
        sort(qspeed,qspeed+n);//升序排列
        int x1=0,y1=0;
        int x2=n-1,y2=n-1;
        for(int i=0;i<n;i++){
            if(tspeed[x1]>qspeed[y1]){
                sum+=200;
                x1++;
                y1++;
            }
             else if(tspeed[x1]<qspeed[y1]){
                sum-=200;
                x1++;
                y2--;
            }
            else{
                if(tspeed[x2]>qspeed[y2]){
                    sum+=200;
                    x2--;
                    y2--;
                }
                else if(tspeed[x1]<qspeed[y2]){
                    sum-=200;
                    x1++;
                    y2--;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}