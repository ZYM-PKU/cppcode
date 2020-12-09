#include<bits/stdc++.h>
using namespace std;

class Int{
public:
    Int(){}
    Int(int _n):n(_n){}
    Int(const Int& in):n(in.n){}
    Int& operator= (const Int& in){
        n=in.n;
        return *this;
    }
    ~Int(){}
    Int operator+(const Int& in){return Int{n + in.n};}
    Int operator-(const Int& in){return Int{n - in.n};}
    Int operator*(const Int& in){return Int{n * in.n};}
    Int operator/(const Int& in){
        if(in.n==0)throw exception{"divided by zero!"};
        return Int{n / in.n};
    }

    friend istream& operator>>(istream& is,Int& in);
    friend ostream& operator<<(ostream& os,const Int& in);
private:
    int n;
};

istream& operator>>(istream& is,Int& in){
    is>>in.n;
    return is;
}
ostream& operator<<(ostream& os,const Int& in){
    os<<in.n;
    return os;
}





int main()
try{
    Int a=0;
    Int b=a;
    Int c;
    cin>>a>>b;
    c=a+b;
    cout<<c<<endl;
    cout<<a/b<<endl;
    return 0;
}
catch (exception& e) {
	cerr << e.what() << endl;
    getchar();
	return 1;
}
catch (...){
	cerr << "exception \n";
    getchar();
	return 2;
}