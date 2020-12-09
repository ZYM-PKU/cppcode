#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
int n;
int len=2;
int a[5000]={0};
int result[5000]={0};
int checklen(int start,int d){//以该元素开始的公差为d的等差序列的长度
    int result1=0;
    int t=1;
    for(int i=start+1;i<n;i++){
        if((a[i]-a[start])==d*t){
            result1++;
            t++;
        }
        if((a[i]-a[start])>d*t)break;//及时停止不必要的循环
    }
    return result1+1;
}
void change(int start, int d){//更新等差序列
    for(int i=0;i<len;i++){
        result[i]=a[start]+(i*d);
    }
}
int main(){
    int d=0;//公差
    int templen=0;//当前序列长度
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);//排序
    for(int i=0;i<n;i++){
        for(int t=1;t+i<n;t++){//遍历公差
            int j;
            j=a[i+t]-a[i];//取合理的公差（剪枝）
            if(j<=(a[n-1]-a[i])/(len-1)){//及时停止遍历
                templen=checklen(i,j);
                if(templen>len){
                len=templen;
                d=j;
                change(i,j);//更新
            }
            else if(templen==len){
                if(j>=d){
                    len=templen;
                    d=j;
                    change(i,j);
                }
            }
            }
        }
    }
    if(len<3){
        cout<<"NO"<<endl;
    }
    else{
        for(int i=0;i<len-1;i++){
            cout<<result[i]<<',';
        }
        cout<<result[len-1];
    }
    return 0;
}