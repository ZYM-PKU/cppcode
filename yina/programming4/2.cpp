#include<bits/stdc++.h>
using namespace std;

vector<int>getlength(vector<string>&a){
    vector<int>lengths;
    for(auto it=a.begin();it!=a.end();it++){
        lengths.push_back(it->length());
    }
    return lengths;
}

int main(){
    vector<string>array;
    while(cin){
        string word;
        cin>>word;
        if(word.length()>0)array.push_back(word);
    }
    vector<int>lengths=getlength(array);
    int longword=0;
    int shortword=0;
    int minlen=0xfffff;
    int maxlen=0;
    for(int i=0;i<lengths.size();i++){
        cout<<lengths[i]<<" ";
        if(lengths[i]>maxlen){maxlen=lengths[i],longword=i;}
        if(lengths[i] < minlen){minlen=lengths[i],shortword=i;}
    }
    cout<<endl;
    cout<<array[longword]<<" "<<array[shortword]<<" ";
    sort(array.begin(),array.end());
    cout<<array[0]<<" "<<array[array.size()-1];
    return 0;
}