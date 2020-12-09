#include<iostream>
using namespace std;
int main(){
    int b[5][7]={0};
    int i=1;
    cout<<b<<endl;
    cout<<&b<<endl;
    cout<<*b<<endl;
    cout<<b[0]<<endl;
    cout<<&b[0]<<endl;
    cout<<&b[0][0]<<endl;
    cout<<*b+1<<endl;
    cout<<b[0]+1<<endl;
    cout<<&b+1<<endl;
    cout<<b+1<<endl;
    cout<<&b[0]+1<<endl;
    cout<<&b[0][0]+1<<endl;
    cout<<**b<<endl;
    return 0;
}