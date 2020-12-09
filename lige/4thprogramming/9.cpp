#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<bitset>
#include<cstdlib>
#include<cmath>
#include<set>
#include<list>
#include<deque>
#include<map>
#include<queue>
using namespace std;
int a[100],b[100];//a是标准数组，b则是最终分解形式，b是a中取一些元素后的变形
int main()
{
    int rs=0,len=0;
    for(int i=2;rs<=1100;i++)
    {
        a[len++]=i;//给a连续赋值，使其两两相邻
        rs+=i;
    }
    int n;
    cin>>n;
     rs=0;
        int k=0;
        for(int i=0;i<len-1;i++)
        {
            rs+=a[i];
            if(n-rs<a[i+1])//将多余数均等分配（不改变原升序排列）
            {
                b[k++]=a[i];
                rs=n-rs;
                int j=k-1;
                while(1)
                {
                    b[j--]++;
                    rs--;
                    if(rs<=0) break;
                    if(j==-1) j=k-1;
                }
                break;
            }
            else if(n-rs==a[i+1])
            {
                b[k++]=a[i];
                b[k++]=a[i+1];
                break;
            }
            else
                b[k++]=a[i];
        }
        cout<<b[0];//以下为输出
        for(int i=1;i<k;i++)
            cout<<' '<<b[i];
    return 0;
}
