#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
long ans = 0;       //最后记录一共有多少逆序对，注意一共至多10^5个人，所以用long
int speed[N];       //输入的速度
int tmp[N];         //merge中的辅助数组



void merge(int left, int right, int middle) {
	for (int i = left; i <= right; i++)
		tmp[i] = speed[i];
	int index1, index2;
	index1 = left; index2 = middle + 1;
	int loc = left;
	while (index1 <= middle && index2 <= right) {
		if (tmp[index1] <= tmp[index2])
			speed[loc++] = tmp[index1++];
		else {
			ans += (middle - index1 + 1);  //更新answer
			speed[loc++] = tmp[index2++];
		}
	}
	while (index1 <= middle)
		speed[loc++] = tmp[index1++];
	while (index2 <= right)
		speed[loc++] = tmp[index2++];
}
void mergesort(int left, int right) {
	int middle;
	if (left < right) {
		middle = (left + right) / 2;
		mergesort(left, middle);
		mergesort(middle + 1, right);
		merge(left, right, middle);
	}
}
int main()
{
	int n; cin >> n;
	for (int i = 0; i <n; i++) {
		cin>>speed[i];
		speed[i] = -speed[i];    //将求顺序对转化为求逆序对
	}
	mergesort(0, n - 1);
	cout << ans << endl;
	return 0;
}