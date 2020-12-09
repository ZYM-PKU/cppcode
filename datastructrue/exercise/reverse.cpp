#include<bits/stdc++.h>

using namespace std;

int main(){

    int i, j, k;
    char str[1000]={0};

    stack<char> st;
    cin.get(str,1000);

    for (i = 0; str[i]; i++){
        if (str[i]!=' '){
            st.push(str[i]);
        } 
        else {
            while(!st.empty()){
                cout << st.top();
                st.pop();
            } 
            cout << str[i];
        }
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
}