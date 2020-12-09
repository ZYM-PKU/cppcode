#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
bool checkprime(int a){
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int m;
    cin>>m;
    for(int i=m;i>=1;i--){
        if(checkprime(i)&&checkprime(i-2)){
            cout<<i-2<<' '<<i<<endl;
            break;
        }
    }
    return 0;
}