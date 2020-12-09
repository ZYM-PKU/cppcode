#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
using namespace std;
int target;
char numstr[7] = { 0 };
int num;
int len = 0;
bool flag[7] = { 0 };
int result[100] = { 0 };
int counting = 1;//记录一共几个可行结果
int maximum;
struct method {
	int result;
	int part[100];
	int c;
}methods[100];
void suming() {
	char divide[7][7] = { 0 };
	int div[7] = { 0 };
	int pos = 0;
	int count = 0;
	int sum=0;
	for (int i = 0; i < len; i++) {
		if (flag[i]) {
			divide[count][pos++] = numstr[i];
			count++;
			pos = 0;
		}
		else {
			divide[count][pos++] = numstr[i];
		}
	}
	for (int i = 0; i <= count; i++) {
		div[i] = atoi(divide[i]);
		methods[counting].part[i] = div[i];
		sum += div[i];
	}
	methods[counting].c = count;
	methods[counting++].result = sum;
	return;
}
void setflag(int count, int pos) {
	if (count == len) {
		return;
	}
	else {
		for (int i = pos; i < len - 1; i++) {
			if (!flag[i]) {
				flag[i] = true;
				suming();
				setflag(count + 1, i + 1);
				flag[i] = false;
			}
		}
	}
}
int  main() {
	while (cin >> target >> numstr) {
		if (target == 0 && numstr[0] == '0')break;
		num = atoi(numstr);//化为整形
		len = strlen(numstr);
		methods[0].result = num;
		setflag(1, 0);
		for (int i = 0; i < counting; i++) {
			if (methods[i].result <= target) {
				if (methods[i].result > maximum) {
					maximum = methods[i].result;
				}
			}
		}
		int tempcount = 0;
		int cal = 0;
		for (int i = 0; i < counting; i++) {
			if (methods[i].result == maximum) {
				if(tempcount==0)cal = i;
				tempcount++;
			}
		}
		if (tempcount == 1) {
			if (cal == 0) {
				cout << num << ' '<<num<<endl;
			}
			else {
				cout << methods[cal].result;
				for (int i = 0; i <= methods[cal].c; i++) {
					cout << ' ' << methods[cal].part[i];
				}
				cout << endl;
			}
		}
		else if (tempcount == 0) {
			cout << "error" << endl;
		}
		else {
			cout << "rejected" << endl;
		}
		for (int i = 0; i < counting; i++) {
			methods[i].c = methods[i].result = 0;
			memset(methods[i].part, 0, sizeof(methods[i].part));
		}
		maximum = 0;
		memset(numstr, '\0', sizeof(numstr));
		memset(flag, 0, sizeof(flag));
		counting = 1;
	}

	return 0;
} 