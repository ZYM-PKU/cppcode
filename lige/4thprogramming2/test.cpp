#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
using namespace std;
char num[110] = { 0 };
int target;
void deleting(int pos, char a[]) {//删除数字串中某位置的数
	int len = strlen(a);
	for (int i = pos; i < len; i++) {
		a[i] = a[i + 1];
	}
}
void deletezero(char a[]) {//删除前置的‘0’
	while (a[0] == '0' && strlen(a) > 1) {
		deleting(0, a);
	}
}

int main() {
	cin >> num >> target;
	for (int pos = 0; pos < strlen(num); pos++) {
		if (target == 0)break;
		for (int i = pos + 1; i < strlen(num); i++) {
			if (target == 0)break;
			if (num[i] < num[pos] && (i - pos) <= target) {
				for (int j = i - 1; j >= pos; j--) {
					deleting(j, num);
					target--;
				}
				i = pos;
			}
			else if (num[i] == num[pos] && (i - pos) <= target+1) {
				for (int j = i - 1; j > pos; j--) {
					deleting(j, num);
					target--;
				}
				pos++;
				i = pos;
			}
		}

	}
	for (int i = strlen(num) - 1; target > 0; i--) {
		deleting(i, num);
		target--;
	}
	deletezero(num);
	cout << num << endl;
	return 0;
}