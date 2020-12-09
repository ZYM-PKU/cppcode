#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
int atlas[600][600]={0};
void filling(int x1,int y1,int x2,int y2){
    for(int i=x1;i<=x2-1;i++){
        for(int j=y1;j<=y2-1;j++){
            atlas[i][j]=1;
        }
    }
}
bool check(int x1,int y1,int x2,int y2){
    for(int i=x1;i<=x2-1;i++){
        for(int j=y1;j<=y2-1;j++){
            if(atlas[i][j]==0)return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    int judge,x1,y1,x2,y2;
    for(int i=0;i<n;i++){
        cin>>judge>>x1>>y1>>x2>>y2;
        if(judge){
            if(check(x1,y1,x2,y2)){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
        else{
            filling(x1,y1,x2,y2);
        }
    }
    return 0;
}