#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    char codea[100][150]={0};
    char codeb[100][150]={0};
    int lena,lenb;
    int countifa=0,countifb=0,countswa=0,countswb=0,countfora=0,countforb=0,countwha=0,countwhb=0;
    cin>>lena;
    cin.get();
    for(int i=1;i<=lena;i++){
        cin.getline(codea[i],100);
        for(int j=0;j<strlen(codea[i]);j++){
            if(codea[i][j]=='i'&&codea[i][j+1]=='f'&&codea[i][j+2]==' ')countifa++;
            if(codea[i][j]=='s'&&codea[i][j+1]=='w'&&codea[i][j+2]=='i'&&codea[i][j+3]=='t'&&codea[i][j+4]=='c'&&codea[i][j+5]=='h')countswa++;
            if(codea[i][j]=='f'&&codea[i][j+1]=='o'&&codea[i][j+2]=='r')countfora++;
            if(codea[i][j]=='w'&&codea[i][j+1]=='h'&&codea[i][j+2]=='i'&&codea[i][j+3]=='l'&&codea[i][j+4]=='e')countwha++;
        }
    }
    cin>>lenb;
    cin.get();
    for(int i=1;i<=lenb;i++){
        cin.getline(codeb[i],100);
         for(int j=0;j<strlen(codeb[i]);j++){
            if(codeb[i][j]=='i'&&codeb[i][j+1]=='f'&&codeb[i][j+2]==' ')countifb++;
            if(codeb[i][j]=='s'&&codeb[i][j+1]=='w'&&codeb[i][j+2]=='i'&&codeb[i][j+3]=='t'&&codeb[i][j+4]=='c'&&codeb[i][j+5]=='h')countswb++;
            if(codeb[i][j]=='f'&&codeb[i][j+1]=='o'&&codeb[i][j+2]=='r')countforb++;
            if(codeb[i][j]=='w'&&codeb[i][j+1]=='h'&&codeb[i][j+2]=='i'&&codeb[i][j+3]=='l'&&codeb[i][j+4]=='e')countwhb++;
        }
    }
    //读入两份程序
    if(((countifa+countswa)==(countifb+countswb))&&((countfora+countwha)==(countforb+countwhb))){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}