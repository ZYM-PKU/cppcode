#include<bits/stdc++.h>
using namespace std;

bool isprime(int n){
    if(n==1)return false;
    if(n==2)return true;
    else{
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0)return false;
        }
        return true;
    }
}
int main(){
    int x,y;
    cin>>x>>y;
    int count=0;
    for(int i=x;i<=y;i++){
        if(isprime(i))count++;
    }
    cout<<count<<endl;
    return 0;
}