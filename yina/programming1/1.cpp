#include<bits/stdc++.h>

using namespace std;
int main(){
    string mychoice,opchoice;
    cin>>mychoice>>opchoice;
    if((mychoice=="Rock"&&opchoice=="Scissors")||(mychoice=="Scissors"&&opchoice=="Paper")||(mychoice=="Paper"&&opchoice=="Rock"))cout<<"You win!"<<endl;
    else if((opchoice=="Rock"&&mychoice=="Scissors")||(opchoice=="Scissors"&&mychoice=="Paper")||(opchoice=="Paper"&&mychoice=="Rock"))cout<<"You lose!"<<endl;
    else cout<<"Continue again!"<<endl;
    return 0;
}