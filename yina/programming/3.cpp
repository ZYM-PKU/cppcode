#include<bits/stdc++.h>
using namespace std;

template<class T>
void comp(T a,char c,T b){
    switch(c){
        case '+':{cout<<a+b<<endl; break;}
        case '-': { cout << a - b << endl; break; }
        case '*': { cout << a * b << endl; break; }
        case '/':{
            cout<<fixed<<setprecision(6)<<a/b<<endl;
        }
    }
}

int main(){
    char compute;
    double a,b;
    cin>>a>>compute>>b;
    comp(a,compute,b);
    return 0;
}