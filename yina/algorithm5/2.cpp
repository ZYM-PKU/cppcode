#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int a[1100]={0};
    int maxlen[1100]={0};

    cin>>n;
    for(int i=1;i<=n;i++){cin>>a[i];maxlen[i]=1;}
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]<a[i])maxlen[i]=max(maxlen[i],maxlen[j]+1);
        }
    }
    cout<<*max_element(maxlen+1,maxlen+n+1)<<endl;
    return 0;
}