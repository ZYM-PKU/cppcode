#include<bits/stdc++.h>
using namespace std;

struct Reading{
    char state;
    int hour;                // 在[0:23]区间取值的小时数
    double temperature;      // 华氏温度
    Reading():hour(0),temperature(0),state('f'){}
    Reading(int _hour,double _temperature):hour(_hour),temperature(_temperature),state('f'){}
    friend ofstream& operator<<(ofstream& of,Reading& re);
    friend istream& operator>>(istream& is,Reading& re);
    void trans2oc(){temperature=(temperature-32)/1.8;state='c';}
};


vector<Reading> temps;

ofstream& operator<<(ofstream& of,Reading& re){
    re.trans2oc();
    of<<re.hour<<" "<<re.temperature<<endl;
    return of;
}

istream& operator>>(istream& is,Reading& re){
    is>>re.hour>>re.temperature;
    return is;
}

int main(){
    ofstream myfile("store_temps.txt");
    while(1){
        char test;
        if(cin>>test)cin.putback(test);
        else break;
        Reading re;
        cin>>re;
        myfile<<re;
    }
}