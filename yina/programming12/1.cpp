#include<bits/stdc++.h>
using namespace std;

char* strdup(const char* ostr){
    int ostrlen=0;
    for(int i=0;;i++){
        if(ostr[i]==0){
            ostrlen=i+1;
            break;
        }
    }
    char* result=new char[ostrlen];
    for(int i=0;i<ostrlen;i++){
        result[i]=ostr[i];
    }
    return result;
}


int main(){
    char origin[10]={0};
    cin>>origin;
    char* result=strdup(origin);
    cout<<result<<endl;
    delete[] result;
    return 0;
}