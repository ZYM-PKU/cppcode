#include <iostream>
using namespace std;
int b[210000], aMaxLen[210000];
int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> b[i];
	aMaxLen[1] = 1;
	for (int  i = 2; i <= N; i++)
	{				  //每次求以第i 个数为终点的最长上升子序列的长度
		int nTmp = 0; //记录满足条件的第i 个数左边的上升子序列的最大长度
		for (int j = 1; j < i; j++)
		{ //察看以第j 个数为终点的最长上升子序列
			if (b[i] > b[j])
			{
				if (nTmp < aMaxLen[j])
					nTmp = aMaxLen[j];
			}
		}
		aMaxLen[i] = nTmp + 1;
	}
	int nMax = -1;
	for (int i = 1; i <= N; i++)
		if (nMax < aMaxLen[i])
			nMax = aMaxLen[i];
	cout << nMax;
	return 0;
}