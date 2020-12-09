#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include<string>
#define e 2.71828
using namespace std;
int main(){
	int a[10]={0};
	int b[10]={0};

	double value=0;
	for(int n=100000000;n<=110000000;n++){
		for(int k=1;k<=n;k++){
			value+=pow(e,(double)k/(double)n)/(n+1/(double)k);
		}
		cout<<"Simulating case:"<<n<<"   value: "<<fixed<<setprecision(15)<<value<<endl;
		value=0;
	}
	return 0;

}