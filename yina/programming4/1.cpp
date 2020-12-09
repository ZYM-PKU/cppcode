#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<string,int>a,pair<string,int>b){return a.first<b.first;}
int main(){
    pair<string,int> individuals[5];
    for(int i =0;i < 5; i++)cin>>individuals[i].first;
    for(int i =0;i < 5; i++)cin>>individuals[i].second;
    vector<pair<string,int>> array;
    for(int i=0;i<5;i++)array.push_back(individuals[i]);
    sort(array.begin(),array.end(),cmp);
    for(auto it=array.begin();it!=array.end();it++){
        cout<<"("<<it->first<<", "<<it->second<<")"<<" ";
    }
    return 0;
}