#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

string pow2(string origin) {
	int add = 0;
	int a=1;
	cout<<a;
	for (int i = origin.length() - 1; i >= 0; i--) {
		int temp = origin[i];
		origin[i] = ((origin[i] - '0') * 2 + add) % 10 + '0';
		add = ((temp - '0') * 2 + add) / 10;
	}
	if (add != 0) {
		string ins;
		ins = add + '0';
		origin.insert(0, ins);
	}
	return origin;
}
string get2pow(int n) {
	if (n == 0)return "1";
	else if (n == 1)return "2";
	else return pow2(get2pow(n - 1));
}
int main() {
	cout<<1;
	string str;
	cin >> str;
	for (int i = 0; i < 3500; i++) {
		if (get2pow(i) >= str&&get2pow(i).length()>=str.length()) {
			cout << i << endl;
			break;
		}
	}
	
	return 0;
}