#include <iostream>
#include<algorithm>
using namespace std;
struct number{
    int b;
    int aMaxLen;
}num[210000];
int maxlen[210000]={0};
bool cmp(number a,number b){
    return a.aMaxLen<b.aMaxLen;
}
int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> num[i].b;
        num[1].aMaxLen = 1;
        maxlen[1]=1;
    for (int i = 2; i <= N; i++)
    {                 //每次求以第i 个数为终点的最长上升子序列的长度
        num[i].aMaxLen= 1;
        sort(num,num+i,cmp);
        for(int j=i-1;j>=0;j--){
            if(num[i].b>num[j].b){num[i].aMaxLen=num[j].aMaxLen+1;break;}
        }
    }
    int nMax = -1;
    for (int i = 1; i <= N; i++)
        if (nMax < num[i].aMaxLen)
            nMax = num[i].aMaxLen;
    cout<<nMax<<endl;
    return 0;
}