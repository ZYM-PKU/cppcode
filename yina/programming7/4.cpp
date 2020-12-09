#include<bits/stdc++.h>
using namespace std;
int main(){
    string word;
    cin>>word;
    vector<string>lines;
    cin.get();
    while(cin){
        char line[1000];
        cin.getline(line,1000);
        string strline=(string)line;
        lines.push_back(strline);
    }
    for(int i=0;i<lines.size();i++){
        if(lines[i].find(word)!=-1){
            cout<<i+1<<" ";
            cout<<lines[i]<<endl;
        }
    }
    return 0;
}