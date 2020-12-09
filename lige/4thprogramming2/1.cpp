#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int n;
    int M,N;
    int str1[40]={0};
    int str2[40]={0};
    int result[80]={0};
    cin>>n;
    for(int x=0;x<n;x++){
        cin>>M>>N;
        for(int i=0;i<M;i++)cin>>str1[i];
        for(int i=0;i<N;i++)cin>>str2[i];
        for(int i=0;i<M+N-1;i++){
            for(int j=0;j<M;j++){
                if(i-j>=0&&i-j<=N)result[i]+=str1[j]*str2[i-j];
            }
        }
        cout<<result[0];
        for(int i=1;i<M+N-1;i++){
            cout<<' '<<result[i];
        }
        cout<<endl;
        memset(str1,0,sizeof(str1));
        memset(str2,0,sizeof(str2));
        memset(result,0,sizeof(result));
    }
    return 0;
}