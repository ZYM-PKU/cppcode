#include <iostream>
using namespace std;
int main() {
	int n, m, ca;
	cin >> n >> m;
	int a[n + 3] = {0}, b[n + 3] = {0}, t[n + 3]; 
	int sumj = 0, sumo = 0, num = 1;
	t[0] = 0;
	t[n + 1] = m;
	for(int i = 1; i <= n; i++) cin >> t[i];
	for(int i = 1; i <= n + 1; i++) {
		if(i % 2 == 1) sumj += t[i] - t[i - 1];
		else sumo += t[i] - t[i - 1];
	}
	b[0] = sumo;
	for(int i = 1; i <= n + 1; i++) {
		if(i % 2 == 1) {
			a[i] = a[i - 1] + t[i] - t[i - 1];
			b[i] = b[i - 1]; 
		}
		else {
			a[i] = a[i - 1];
			b[i] = b[i - 1] - t[i] + t[i - 1];
		}
	}
	int maxn = sumj;
	for(int i = 1; i <= n + 1; i++) {
		maxn = max(maxn, a[i] + b[i] - 1);
	}
	cout << maxn << endl;	
	return 0;
} 
