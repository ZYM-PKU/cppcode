#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
using namespace std;


class String{
    private:
    char *str;
    public:
    String():str(NULL){}
    const char *c_str(){return str;}
    char *operator=(const char *s);
    String & operator=(const String &s){
        if(str) delete []str;
        str= new char[strlen(s.str)+1];
        strcpy(str,s.str);
        return *this;
    }//重载的=函数实现了深拷贝
    ~String();
};

char *String::operator=(const char * s){
    if(str) delete []str;
    if(s){
        str = new char[strlen(s)+1];
        strcpy(str,s);
    }
    else str=NULL;
    return str;
}

String::~String(){
    if(str) delete []str;
}

int main(){
    String s,s1;
    s="good luck";
    s1=s;
    cout<<s.c_str()<<endl;
    cout<<s1.c_str()<<endl;
    s1="bad luck";
    cout<<s.c_str()<<endl;
    return 0;
}