#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
using namespace std;
int main() {
    char words[200][30]={0};
    char str[2000]={0};
    int n,m;
    int wordlen;
    char tempword[30]={0};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>words[i];
    }
    wordlen=strlen(words[1]);
    for(int x=0;x<m;x++){
        cin>>str;
        bool result=true;
        if(strlen(str)%wordlen!=0){
            cout<<"No"<<endl;
             memset(str,'\0',sizeof(str));
            continue;
        }
        int count=strlen(str)/wordlen;
        int pos=0;
        for(int i=0;i<count;i++){
            int judging=false;
            pos=wordlen*i;
            for(int j=0;j<wordlen;j++){
                tempword[j]=str[pos+j];
            }
            for(int t=1;t<=n;t++){
                if(strcmp(tempword,words[t])==0){
                    judging=true;
                }
            }
            if(judging==false){
                result=false;
                break;
            }
            memset(tempword,'\0',sizeof(tempword));
        }
        if(result){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
        memset(str,'\0',sizeof(str));

    }



	return 0;
}