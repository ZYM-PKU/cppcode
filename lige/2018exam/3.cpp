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
bool checksquare(int a){
    if(a==0)return false;//注意：0的情况要特殊考虑
    int b=(int)sqrt(a);
    if(a==b*b)return true;
    return false;
}
bool divide(int a){//将大整数分解，对每部分检查
    int pos[9]={0};
    int len=0;
    int temp;
    while(a!=0){
        pos[len++]=a%10;
        a/=10;//取各位数
    }
    for(int i=0;i<len/2;i++){
        temp=pos[i];
        pos[i]=pos[len-1-i];
        pos[len-1-i]=temp;
    }//倒序输出
    int first=pos[0]*100+pos[1]*10+pos[2];
    int end=pos[len-3]*100+pos[len-2]*10+pos[len-1];
    if(checksquare(end)&&checkprime(first)){
        for(int i=0;i<len-1;i++){
            if(pos[i]==1&&pos[i+1]==3)return false;
        }
        return true;
    }
    return false;
}
int main(){
    int n,m;
    cin>>m>>n;
    int count=0;
    for(int i=m;i<=n;i++){
        if(divide(i)){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}