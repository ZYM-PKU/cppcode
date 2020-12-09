#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    int k1,k2,k3;
    while(cin>>k1>>k2>>k3){
        if(k1==0&&k2==0&&k3==0)break;
        else{
            char str[1000]={0};
            char str1[1000]={0};
            char str2[1000]={0};
            char str3[1000]={0};
            int len1=0,len2=0,len3=0;
            int t1=0,t2=0,t3=0;
            cin>>str;
            for(int i=0;i<strlen(str);i++){
                if(str[i]>='a'&&str[i]<='i'){
                    str1[len1++]=str[i];
                }
                else if(str[i]>='j'&&str[i]<='r'){
                    str2[len2++]=str[i];
                }
                else{
                    str3[len3++]=str[i];
                }
            }//分组读入
            for(int i=1;i<=k1;i++){
                for(int j=len1;j>0;j--){
                    str1[j]=str1[j-1];
                }
                str1[0]=str1[len1];
                str1[len1]='\0';
            }//向右循环旋转
            for(int i=1;i<=k2;i++){
                for(int j=len2;j>0;j--){
                    str2[j]=str2[j-1];
                }
                str2[0]=str2[len2];
                str2[len2]='\0';
            }//向右循环旋转
            for(int i=1;i<=k3;i++){
                for(int j=len3;j>0;j--){
                    str3[j]=str3[j-1];
                }
                str3[0]=str3[len3];
                str3[len3]='\0';
            }//向右循环旋转
            for(int i=0;i<strlen(str);i++){
                if(str[i]>='a'&&str[i]<='i'){
                    str[i]=str1[t1++];
                }
                else if(str[i]>='j'&&str[i]<='r'){
                    str[i]=str2[t2++];
                }
                else{
                    str[i]=str3[t3++];
                }
            }//反向赋值
            cout<<str<<endl;
        }
    }


    return 0;
}