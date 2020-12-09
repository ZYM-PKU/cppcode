#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
using namespace std;
void deleting(char a[],int pos){
    for(int i=pos;i<strlen(a);i++){
        a[i]=a[i+1];
    }
    return;
}
double changetof(char a[]){
    double result=0;
    bool zheng=true;
    bool judge=false;
    int pos=65;
    bool zheng1=true;
    if(a[0]=='+'){
        deleting(a,0);
    }
    if(a[0]=='-'){
        zheng=false;
        deleting(a,0);
    }
    char temp1[65]={0};
    char temp2[65]={0};
    for(int i=0;i<strlen(a);i++){
        if(a[i]=='e'){
            for(int j=i+1;j<strlen(a);j++){
                temp2[j-i-1]=a[j];
            }
            break;
        }
        temp1[i]=a[i];
        if(temp1[i]=='.'){
            judge=true;
            pos=i;
        }
    }
    if(temp2[0]=='-'){
        zheng1=false;
        deleting(temp2,0);
    }
    if(!judge){
        pos=strlen(temp1);
    }
    for(int i=pos-1;i>=0;i--){
        result+=(temp1[i]-'0')*pow(10.0,pos-i-1);
    }
    for(int i=pos+1;i<strlen(temp1);i++){
        result+=(temp1[i]-'0')*pow(10.0,pos-i);
    }
    int fang=0;
    for(int i=strlen(temp2)-1;i>=0;i--){
        fang+=(temp2[i]-'0')*pow(10.0,(double)(strlen(temp2)-1-i));
    }
    if(!zheng){
        result=-result;
    }
    if(zheng1){
        result=result*pow(10.0,fang);
    }
    else{
        result=result*pow(10.0,-fang);
    }
    return result;

}
int main(){
    char str[50]={0};
    while(cin>>str){
        if(str[0]=='q')break;
        for(int i=0;i<strlen(str);i++){
            if(!((str[i]>='0'&&str[i]<='9')||str[i]=='+'||str[i]=='-'||str[i]=='.')){
                str[i]='e';
            }
        }
        double result=changetof(str);
        cout<<fixed<<setprecision(6)<<result<<endl;
        memset(str,'\0',sizeof(str));
    }
    return 0;
}