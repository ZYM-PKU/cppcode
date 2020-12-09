#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
using namespace std;


class Demo{
    int id;
    public:
    Demo(int i){
        id =i;
        cout<<"id="<<id<<" Constructed"<<endl;
    }
    ~Demo(){
        cout<<"id="<<id<<" Destructed"<<endl;
    }
};
Demo d1(1);
void Func(){
    static Demo d2(2);
    Demo d3(3);
    cout<<"Func1 start operating"<<endl;
}
int main(){
    for(int i=1;i<=10000;i++){
        cout<<"operating files number: "<<i<<" ..."<<endl;
    }
    Demo d4(4);
    d4=6;
    cout<<"main func start operating..."<<endl;
    {Demo d5(5);}
    Func();
    
    cout<<"main func operation ends."<<endl;
    
    return 0;
}