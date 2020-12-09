#include<bits/stdc++.h>
using namespace std;


int main() {
	int n1, n2;
	cin >> n1 >> n2;
	set<int> set1;
	for (int i = 0; i < n1 + n2; i++) { int c; cin >> c; set1.insert(c); }
	int i = 0;
	for (auto iter = set1.begin(); iter != set1.end(); iter++) {
		if (iter != --set1.end()) {
			cout << *iter << " ";
		}
		else cout << *iter << endl;
	}
	return 0;
}