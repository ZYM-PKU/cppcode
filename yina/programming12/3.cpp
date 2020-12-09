#include<bits/stdc++.h>
using namespace std;
int main(){
    long long count=0;
    cout<<""
    while(1){
        try{
            int* newint =new int[100];
            count++;
        }
        catch(bad_alloc){
            cout<<"内存压力测试完毕。"<<endl;
            cout<<"共申请了： "<<count*sizeof(int)*100<<" 字节"<<endl;
            break;
        }
    }
    return 0;
}