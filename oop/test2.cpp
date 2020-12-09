#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
using namespace std;

class X{
    public:
    int n;
    X(int x){n=x;}//自定义构造函数
    X(X &c){n=c.n*2;}//自定义复制构造函数（参数是同类的引用）

};
int main(){
    X x1(5);
    X x2(x1);
    cout<<x1.n<<' '<<x2.n;

    return 0;
}