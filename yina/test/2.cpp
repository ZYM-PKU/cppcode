#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> numstack;
        for(int i=0;i<num.length();i++){
            while(k&&!numstack.empty()&&numstack.top()>num[i]){numstack.pop();k--;}
            numstack.push((char)num[i]);
        }
        string result;
        while(!numstack.empty()){
            result.push_back(numstack.top());numstack.pop();
        }
        reverse(result.begin(),result.end());
        cout<<result<<endl;
        if(k)result=result.substr(0,result.length()-k);
        for(int i=0;i<result.length();i++){
            if(result[i]=='0')result.erase(i--,1);
            else break;
        }
        if(result.length()==0)result="0";
        return result;

    }
};



int main(){
    string s;
    int k;
    cin>>s;
    cin>>k;
    Solution sol;
    cout<<sol.removeKdigits(s,k);

    return 0;
}