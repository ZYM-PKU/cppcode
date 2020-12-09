#include<iostream>
#include<fstream>
using namespace std;

int main() {
	char c;
	int counting[11] = { 0 };
	while (cin) {
		c = cin.get();
		if (isspace(c))counting[0]++;
		if (isalpha(c))counting[1]++;
		if (isdigit(c))counting[2]++;
		if (isxdigit(c))counting[3]++;
		if (isupper(c))counting[4]++;
		if (islower(c))counting[5]++;
		if (isalnum(c))counting[6]++;
		if (iscntrl(c))counting[7]++;
		if (ispunct(c))counting[8]++;
		if (isprint(c))counting[9]++;
		if (isgraph(c))counting[10]++;
	}
	counting[0]--;
	counting[7]--;
	for (int i = 0; i < 11; i++)cout << counting[i] << endl;
	return 0;
}