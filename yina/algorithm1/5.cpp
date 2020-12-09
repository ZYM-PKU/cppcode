#include<bits/stdc++.h>
using namespace std;


bool cmp(int a,int b){return a>b;}
int main(){
    int n,m;
    cin>>m>>n;
    vector<int>nums;
    for(int i=0;i<n;i++){int c;cin>>c;nums.push_back(c);}
    sort(nums.begin(),nums.end());
    int add1=accumulate(nums.begin(),nums.begin()+m,0);
    sort(nums.begin(),nums.end(),cmp);
    int add2=accumulate(nums.begin(),nums.begin()+m,0);
    int add=accumulate(nums.begin(),nums.end(),0);
    cout<<fixed<<setprecision(2)<<(double)(add-add1-add2)/(n-2*m)<<endl;
    return 0;
}