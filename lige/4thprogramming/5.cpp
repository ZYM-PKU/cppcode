#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int n;
    char str[600]={0};
    char gram[600][6]={0};
    int time[600]={0};
    int maxtime=0;
    cin>>n;
    cin.get();
    cin.getline(str,600);
    for(int i=0;i<600;i++){
        time[i]=1;
    }
    for(int i=0;i<strlen(str)-n+1;i++){
        for(int j=0;j<n;j++){
            gram[i][j]=str[i+j];//提取子串
        }
    }
    for(int i=0;i<strlen(str)-n+1;i++){
        if(time[i]!=-1){
            for(int j=i+1;j<strlen(str)-n+1;j++){
            if(strcmp(gram[i],gram[j])==0){
                time[i]++;
                time[j]=-1;//标记
            }
        }
        }
    }
    maxtime=*max_element(time,time+600);//取最大值
    if(maxtime==1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<maxtime<<endl;
        for(int i=0;i<strlen(str)-n+1;i++){
            if(time[i]==maxtime){
                cout<<gram[i]<<endl;
            }
        }
    }


    return 0;
}