#include<bits/stdc++.h>
using namespace std;


bool light[1100]={0};
void change(int n){light[n]=!light[n];}
int main(){
    int n,k;
    cin>>n>>k;
    for(int c=1;c<=k;c++){
        for(int i=1;i<=n;i++){
            if(i%c==0)change(i);
        }
    }
    bool first=true;
    for(int i=1;i<=n;i++){
        if(light[i]){
            if(first){cout<<i;first=false;}
            else cout<<" "<<i;
        }
    }
    cout<<endl;

}