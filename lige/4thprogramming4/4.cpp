#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stdlib.h>

using namespace std;
double notation(){
    char str[10];
    cin>>str;
    switch(str[0]){
        case '+':return notation()+notation();
        case '-':return notation()-notation();
        case '*':return notation()*notation();
        case '/':return notation()/notation();
        default: return atof(str);
    }
}
int main(){
    cout<<fixed<<setprecision(6)<<notation();
    return 0;
}