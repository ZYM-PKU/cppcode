#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stdlib.h>

using namespace std;
int main(){
    int N;
    int a[200][200]={0};
    int result[200][200]={0};
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
        }

    }
    for(int i=N;i>=1;i--){
        for(int j=1;j<=i;j++){
            if(i==N){
                result[i][j]=a[i][j];
            }
            else{
                result[i][j]=a[i][j]+max(result[i+1][j],result[i+1][j+1]);
            }
        }
    }
    cout<<result[1][1]<<endl;
    return 0;
}