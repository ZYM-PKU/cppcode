#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
using namespace std;


class Ctyre{
    private:
    int radius;
    int width;
    public:
    Ctyre(int r,int w):radius(r),width(w){}
};
class Cengine{
    
};

class Ccar{
    private:
    int price;
    Ctyre tyre;
    Cengine engine;
    public:
    Ccar(int p,int tr,int tw);
};
Ccar::Ccar(int p, int tr, int tw):price(p),tyre(tr,tw){}


class A{
    private:
    int a;
    friend class B;//向B类“敞开心扉”
};
class B{
    private:
    int b;
    public:
    A ta;
    void printa(){cout<<ta.a<<endl;}
};


int main(){
    Ccar car(20000,20,10);
    cout<<1<<endl;
    return 0;

}