#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
using namespace std;
int row, col;
char direction;
int dir = 0;
char atlas[1000][1000] = { 0 };
int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int startx, starty, endx, endy;
bool judge = false;
int time1[1000][1000] = { 0 };
void explore(int d, int x, int y) {//三个参数：当前方向，当前位置
	time1[x][y]++;
	if (time1[x][y] > 3)return;
	if (x == endx && y == endy) {
		judge = true;
		return;
	}
	if (atlas[x + dx[(d + 1) % 4]][y + dy[(d + 1) % 4]] != '#') {
		explore((d + 1) % 4, x + dx[(d + 1) % 4], y + dy[(d + 1) % 4]);
	}
	else if (atlas[x + dx[d]][y + dy[d]] != '#') {
		explore(d, x + dx[d], y + dy[d]);
	}
	else if (atlas[x + dx[(d + 3) % 4]][y + dy[(d + 3) % 4]] != '#') {
		explore((d + 3) % 4, x + dx[(d + 3) % 4], y + dy[(d + 3) % 4]);
	}
	else {
		explore((d + 2) % 4, x, y);
	}
	return;
}
int main() {
	while (cin >> row >> col) {
		    for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				cin >> atlas[i][j];
				if (atlas[i][j] == 'S') {
					startx = i; starty = j;
				}
				if (atlas[i][j] == 'T') {
					endx = i, endy = j;
				}
			}
		cin >> direction;
		switch (direction) {
		case 'N':dir = 0; break;
		case 'W':dir = 1; break;
		case 'S':dir = 2; break;
		case 'E':dir = 3; break;
		}
		explore(dir, startx, starty);
		if (judge)cout << "YES" << endl;
		else cout << "NO" << endl;
		memset(atlas, '\0', sizeof(atlas));
		memset(time1, 0, sizeof(time1));
		judge = false;
	}

	return 0;
}