#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include<stack>

using namespace std;

int main(){
    stack<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.pop();
    cout<<a.top()<<endl;
    cout<<a.size()<<endl;

    return 0;
}