#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int N;
    cin>>N;
    char str1[200]={0};
    char str2[200]={0};
    int samelen[200][200]={0};
    for(int t=0;t<N;t++){
        int result=0;
        cin>>str1>>str2;
        for(int i=1;i<=strlen(str1);i++){
            for(int j=1;j<=strlen(str2);j++){
                if(str1[i-1]==str2[j-1]){
                    samelen[i][j]=samelen[i-1][j-1]+1;
                    result=max(result,samelen[i][j]);
                }
            }
        }
        cout<<result<<endl;
        memset(samelen,0,sizeof(samelen));
        memset(str1,'\0',sizeof(str1));
        memset(str2,'\0',sizeof(str2));
    }
    return 0;
}