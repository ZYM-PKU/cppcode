#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int N,T;
    cin >> N >> T;
    int a[N + 1], dp[T + 1];
    memset(dp,127, sizeof(dp));
    dp[0]=0;
    for (int i = 1; i <= N; i++)cin >> a[i];
    for (int k = 1; k <= T; k++)
    {
        for (int i = N; i >= 1; i--)
        {
            if(a[i]>k)break;
            dp[k]=min(dp[k],dp[k-a[i]]+1);
        }
    }
    cout << dp[T] << endl;
    return 0;
}