#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stdlib.h>

using namespace std;
int num[100]={0};
int strtoint(char a[]){
    
    char shortstr[100][5]={0};
    int temp=0;
    int count1=0;
    for(int i=0;i<strlen(a);i++){
        if(a[i]==' '){
            count1++;
            temp=0;
        }
        else{
            shortstr[count1][temp++]=a[i];
        }
    }
    for(int i=0;i<=count1;i++){
        num[i]=atoi(shortstr[i]);
    }
    return count1;
}
int main(){
    int n;
    cin>>n;
    cin.get();
    for(int i=0;i<n;i++){
        memset(num,0,sizeof(num));
        char str[110]={0};
        cin.getline(str,100);
        int count2=strtoint(str);
        sort(num,num+count2+1);
        for(int i=0;i<count2;i++){
            cout<<num[i]<<' ';
        }
        cout<<num[count2]<<endl;
    }
    return 0;
}