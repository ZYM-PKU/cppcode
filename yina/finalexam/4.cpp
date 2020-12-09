#include<bits/stdc++.h>
using namespace std;


double f(double x,double a){return x*x*x+x+a;}


int main(){
    int cases;
    cin>>cases;
    for(int c=1;c<=cases;c++){
        double a,b;
        cin>>a>>b;
        double x1,x2;
        if(a>0){x2=0;x1=-a;}
        else {x1=0;x2=-a;}
        while(true){
            if((x2-x1)<b){
                cout<<fixed<<setprecision(6)<<(x1+x2)/2<<" "<<f((x1+x2)/2,a)<<endl;
                break;
            }
            double middle=(x1+x2)/2;
            if(f(middle,a)>0)x2=middle;
            else x1=middle;
        }
    }
}