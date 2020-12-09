#include<bits/stdc++.h>
using namespace std;

template<class T>
class Number{
public:
    Number(){}
    Number(T _n):n(_n){}
    Number(const Number& in):n(in.n){}
    Number& operator= (const Number& in){
        n=in.n;
        return *this;
    }
    ~Number(){}
    Number operator+(const Number& in){return Number{n+in.n};}
    Number operator-(const Number& in){return Number{n-in.n};}
    Number operator*(const Number& in){return Number{n*in.n};}
    Number operator/(const Number& in){
        if ( 0 == in.n ) throw  exception{"divide by zero!"} ;
        return Number{n/in.n};
    }
    T value()const{ return n; }
	void set_value(T _n) { n = _n; }
private:
    T n;
};

template<class T>
istream& operator>>(istream& is,Number<T>& in){
    T n;
    is>>n;
    in.set_value(n);
    return is;
}

template<class T>
ostream& operator<<(ostream& os,const Number<T>& in){
    os<<in.value();
    return os;
}





int main()
try{
    Number<double> x = 0.0;  
    Number<double> y = x;  
    Number<double> z;   
    cin >> x >> y;  
    z = (x - y) / y; 
    cout<<(x+y)/z<<endl;
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