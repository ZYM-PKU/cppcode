#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
int main(){
    int n,k;
    bool result=0;
    int num[1500]={0};
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    for(int i=1;i<n;i++){
        if(!result){
            for(int j=i+1;j<=n;j++){
            if(num[i]+num[j]==k){
                result=1;
                break;
            }
        }
        }
    }
    if(result)cout<<"yes"<<endl;
    else{
        cout<<"no"<<endl;
    }
    return 0;
}