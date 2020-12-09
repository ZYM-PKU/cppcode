#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
using namespace std;
int n,f;
int maxstu=0;
struct student{
    int num;//学生喜欢书本的个数
    int books[30];//具体书本
};
student stu[30];
bool used[30]={0};//借用全排列思想
void deepsearch(int s,int count){
    if(s==n){
        maxstu=max(maxstu,count);//更新最值
        return;
    }
    else{
        for(int i=1;i<=stu[s].num;i++){
            if(!used[stu[s].books[i]]){
                used[stu[s].books[i]]=true;
                deepsearch(s+1,count+1);
                used[stu[s].books[i]]=false;//回溯
            }
        }
        deepsearch(s+1,count);//也可以不分书
    }
}
int main(){
    cin>>n>>f;
    for(int i=1;i<=n;i++){
        cin>>stu[i].num;
        for(int j=1;j<=stu[i].num;j++){
            cin>>stu[i].books[j];
        }
    }
    deepsearch(1,0);
    cout<<maxstu<<endl;
    return 0;
}