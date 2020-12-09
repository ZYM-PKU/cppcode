




////////////////////本程序为类的定义与使用示例程序//////////////////////
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
using namespace std;

class rectangle{
    public:
    int w;
    int h;
    int computecircum();
    int computearea();
    void setwh(int w1,int h1);
};

int rectangle::computecircum(){return 2*(w+h);}
int rectangle::computearea(){return w*h;}
void rectangle::setwh(int w1,int h1){
        w=w1;h=h1;//类的成员函数可以访问同类的变量
}
void printr(rectangle r){
    cout<<r.computecircum()<<endl;
    cout << r.computearea() << endl;
}
int main(){
    int w,h;
    cin>>w>>h;
    rectangle r;
    r.setwh(w,h);
    rectangle rr=r;
    printr(rr);
    return 0;
}