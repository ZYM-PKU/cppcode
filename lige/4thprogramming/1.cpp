#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
int main(){
    double a[3]={0};
    int temp[3]={0};
    char dou;
    cin>>*a>>dou>>*(a+1)>>dou>>*(a+2);
    sort(a,a+3);
    for(int i=0;i<3;i++){
        *(temp+i)=*(a+i);
        if((*(a+i)-*(temp+i))!=0){
            cout<<fixed<<setprecision(2)<<*(a+i);
        }
        else{
            cout<<*(a+i);
        }
        if(i<2)cout<<',';
    }
    return 0;
}
