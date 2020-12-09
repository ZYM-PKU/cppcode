#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
using namespace std;
bool compare(int pos,char a[],char b[]){
    for(int i=0;i<=pos;i++){
        if(a[i]!=b[i])return false;
    }
    return true;//表示子串相同
}
int main(){
    int count=0;
    char words[1200][30]={0};
    char wordspart[30]={0};
    while(cin>>words[count++]);
    for(int i=0;i<count;i++){
        for(int j=0;j<strlen(words[i]);j++){
            int result=0;
            wordspart[j]=words[i][j];//不断向后读子串
            for(int t=0;t<count;t++){
                if(t!=i){
                    if(compare(j,wordspart,words[t])){
                        result=1;
                        break;
                    }
                }
            }
            if(result==1&&j!=strlen(words[i])-1)continue;
            cout<<words[i]<<' '<<wordspart<<endl;
            break;
        }
        memset(wordspart,'\0',sizeof(wordspart));
    }
    return 0;
}