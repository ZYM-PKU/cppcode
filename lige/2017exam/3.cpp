#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
int photo[1500][1500]={0};

int main(){
    int n;
    int count=0;
    int firsti,firstj,tempi,tempj;
    bool first=false;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>photo[i][j];
            if(photo[i][j]==0){
                tempi=i;tempj=j;
                if(!first){
                    firsti=i;
                    firstj=j;
                    first=true;
                }
            }

        }
    }
    for(int i=firsti+1;i<tempi;i++){
        for(int j=firstj+1;j<tempj;j++){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}