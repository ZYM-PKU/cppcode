#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int k, m, len;
void add1(char a[]) {
	for (int i = len - 1; i >= 0; i--) {
		if (a[i] - '0' + 1 < k) {
			a[i]++;
			break;
		}
		else {
			a[i] = '0';
			if (i == 0) {
				a[i] = '1';
				a[len] = a[len - 1];
				a[len - 1] = '0';
				len++;
			}
			continue;
		}
	}
}
void prin(char a[], int count) {//count表示输出了几次
	add1(a);
	if ((count + 1) % 5 == 0) {
		cout <<a<< endl;
	}
	else {
		if (count == m - 1) {
			cout << a;
		}
		else {
			cout << a << ',';
		}
	}
	if ((count + 1) < m) {
		prin(a, count + 1);
	}
	return;
}
int main() {
	char dou;
	char number[31] = { 0 };
	cin >> k >> dou >> m >> dou >> number;
	len = strlen(number);//计算k进制数长度
	prin(number, 0);
	return 0;
}