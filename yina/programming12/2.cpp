#include<bits/stdc++.h>
using namespace std;

const char* findx(const char* s, const char* x){
    for(int i=0;i<strlen(s)-strlen(x)+1;i++){
        if(s[i]==x[0]){
            bool check=true;
            for(int j=0;j<strlen(x)-1;j++){
                if(x[j]!=s[i+j]){
                    check=false;
                    break;
                }
            }
            if(check){
                return s+i;
            }
        }
    }
    return s+strlen(s);//默认返回最后一个字符
}

int main(){
    char needle[4]="abc";
    char str[20]={0};
    cin>>str;
    const char* f=findx(str,needle);
    if(f!=str+strlen(str)){
        cout<<*f<<endl;
    }
    else cout<<"not found."<<endl;
    return 0;
}