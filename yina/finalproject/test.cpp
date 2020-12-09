#include<bits/stdc++.h>
using namespace std;
struct deleter {
	template<typename T>
	void operator()(const T* ptr) const { delete ptr; }
};


class Base{
public:
    Base(){}
    ~Base(){cout<<"base called"<<endl;}
    vector<int*>aaa;
};
class A:public Base{
public:
    A(){}
    ~A(){
        for_each(aaa.begin(),aaa.end(),deleter());
        cout<<"called"<<endl;
        }
};





int main(){
    Base* astar=new A;
    int* a=new int(1);
    astar->aaa.push_back(a);
    delete astar;


    vector<int>test={1,2,3,4,5};
    for(auto iter=test.begin();iter!=test.end();iter++){
        if((*iter)==3)test.erase(iter);
    }
    for(int i=0;i<4;i++)cout<<test[i]<<endl;
    return 0;
}