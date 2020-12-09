#include<bits/stdc++.h>
using namespace std;


int maxv(const vector<int>& v) {
    return *max_element(v.begin(),v.end());
}

int main(){
    vector<int>a;
    while(cin){
        int c;cin>>c;a.push_back(c);
    }
    cout<<maxv(a)<<endl;
    return 0;
}