#include<bits/stdc++.h>
using namespace std;

class number{
protected:
    string numstr;
    int classify;
    long change_to_10=0;
public:
    number(){}
    ~number(){}
    friend istream& operator>>(istream& is,number& num);
    void change();
};

istream& operator>>(istream& is,number& num){
    is>>num.numstr;
    if(num.numstr[0]=='0'){
        if(num.numstr[1]=='x'){
            num.classify=16;
            num.numstr.erase(0,2);
        }
        else{
            num.classify=8;
            num.numstr.erase(0,1);
        }
    }
    else{
        num.classify=10;
    }
    return is;
}

void number::change(){
    int pos=0;
    for(int i=numstr.size()-1;i>=0;i--){
        change_to_10+=(int)(numstr[i]-'0')*pow(classify,pos++);
    }
    cout<<change_to_10<<endl;
}

int main(){
    while(1){
        number n;
        if(cin>>n)n.change();
        else break;
    }
    return 0;
}