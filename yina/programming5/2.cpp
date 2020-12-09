#include<bits/stdc++.h>
using namespace std;



class Patron{
protected:
    string name;
    string ID;
    double owemoney;
public:
    string getname()const{return name;}
    string getID()const{return ID;}
    double getowemoney()const{return owemoney;}
    Patron():owemoney(0){}
    Patron(string _name,string _ID,double _owemoney=0):name(_name),ID(_ID),owemoney(_owemoney){}
    void setowemoney(double money){owemoney=money;}
    bool checkowe(){return owemoney;}
    friend ostream& operator <<(ostream& os,Patron& pa);
    friend istream& operator >>(istream& is,Patron& pa);
};

ostream& operator <<(ostream& os,Patron& pa){
    os<<pa.name<<" "<<pa.ID<<" "<<pa.owemoney<<endl;
}

istream& operator >>(istream& is,Patron& pa){
    is>>pa.name>>pa.ID>>pa.owemoney;
}


bool cmp(const Patron& pa1,const Patron& pa2){return pa1.getowemoney()>pa2.getowemoney();}

vector<Patron>Patrons;
int main(){
    while (cin) {
		char test;
		if (cin >> test)cin.putback(test);
		else break;
		Patron PA;
		cin >> PA;
		Patrons.push_back(PA);
	}
    sort(Patrons.begin(),Patrons.end(),cmp);
    for(Patron pa:Patrons){
        if(pa.checkowe())cout<<pa;
    }
    return 0;
}