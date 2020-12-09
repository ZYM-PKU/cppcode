#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long max1 = 0, sum = 0;
	int N, L;
	cin >> N >> L;
	vector<int> a;
	a.resize(2 * N);

	for (int i = 0;i < N;i++)
	{
		cin >> a[i];
	}
	for (int i = 0;i < N;i++)//将原组复制两遍拼接在一起
	{
		a[N + i] = a[i];
	}
	for (int i = 0; i < L; i++)
	{
		sum += a[2 * N - 1 - i];
		max1 = sum;
	}
	for (int k = 0;k < L;k++)
	{
		sum += a[N + k] - a[N - L + k];
		max1 = max(sum,max1);
	}
	cout << max1;
}
