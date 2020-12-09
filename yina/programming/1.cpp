#include<bits/stdc++.h>
using namespace std;
int main(){

    const int size=3;
    vector<string> strs;
    string temp;
    for(int i=0;i<size;i++){
        cin>>temp;
        strs.push_back(temp);
    }
    sort(strs.begin(),strs.end());
    for(int i=0;i<size-1;i++)cout<<strs[i]<<",";
    cout<<strs[size-1]<<endl;
    return 0;

}