#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
bool checkspecial(char a[]){
    for(int i=0;i<=2;i++){
        for(int j=i+1;j<=3;j++){
            if(a[i]==a[j])return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    for(int x=0;x<n;x++){
        char startyear[5]={0};
        cin>>startyear;
        int istartyear;
        istartyear=atoi(startyear);
        for(int y=istartyear+1;y<9999;y++){
            char a[4];
            int temp=y;
            for(int t=3;t>=0;t--){
                a[t]=temp%10+'0';
                temp/=10;
            }
            if(checkspecial(a)){
                cout<<y<<endl;
                break;
            }
        }
    }
    return 0;
}