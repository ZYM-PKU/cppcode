#include<bits/stdc++.h>
using namespace std;

#define infinity 0xfffff
int n;
int origin[20][20] = { 0 };
vector<int>result;
int counting = 0;
int paint() {
	int count = 0;
	int temp[20][20] = { 0 };
	memcpy(temp, origin, sizeof(origin));
	for (int row = 2; row <= n; row++) {
		for (int col = 1; col <= n; col++) {
			if (!temp[row - 1][col]) {
				count++;
				temp[row][col] = !temp[row][col];
				temp[row - 1][col] = !temp[row - 1][col];
				temp[row + 1][col] = !temp[row + 1][col];
				temp[row][col + 1] = !temp[row][col + 1];
				temp[row][col - 1] = !temp[row][col - 1];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!temp[n][i])return infinity;
	}
	return count;
}

void simulate(int col, int count1,bool p) {
	if (col > n)return;
	counting++;
	if (!p) {
		int count = paint();
		if (count != infinity) result.push_back(count1 + count);
		simulate(col + 1, count1,true);
		simulate(col + 1, count1, false);
	}
	else {
		origin[1][col] = !origin[1][col];
		origin[2][col] = !origin[2][col];
		origin[1][col + 1] = !origin[1][col + 1];
		origin[1][col - 1] = !origin[1][col - 1];
		int count = paint();
		if (count != infinity) result.push_back(count1 + count + 1);
		simulate(col + 1, count1 + 1,true);
		simulate(col + 1, count1 + 1,false);
		origin[1][col] = !origin[1][col];
		origin[2][col] = !origin[2][col];
		origin[1][col + 1] = !origin[1][col + 1];
		origin[1][col - 1] = !origin[1][col - 1];
	}
}




int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			if (c == 'y')origin[i][j] = 1;
		}

	simulate(1, 0,true);
	simulate(1, 0, false);
	if (result.size() == 0)cout << "inf" << endl;
	else cout << *min_element(result.begin(), result.end()) << endl;

	return 0;
}