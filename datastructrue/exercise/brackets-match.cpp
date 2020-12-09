#include<bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin>>str;
    stack<char>bstack;
    for(int i=0;i<str.size();i++){
        if (str[i]=='(')bstack.push(str[i]);
        else{
            if (bstack.empty()){
                cout<<"No";
                return 0;
            }
            else bstack.pop();
        }
    }
    if(bstack.empty()){
        cout<<"Yes";
    }
    else cout<<"No";
    return 0;
}