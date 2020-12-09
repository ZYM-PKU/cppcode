#include<bits/stdc++.h>
using namespace std;



int rp(int a, int b)
{
	while(1)
    {          // 求出两个正整数的最大公约数
		int t = a%b;
		if(t == 0)break;
		else{a = b;b = t;}
	}
	return b;
}

class fraction{
protected:
    int numerator;
    int denominator;
public:
    fraction():numerator(0),denominator(0){}
    fraction(int _numerator,int _denominator):numerator(_numerator),denominator(_denominator){
        numerator=numerator/rp(_numerator,_denominator);
        denominator=denominator/rp(_numerator,_denominator);//默认直接约分
    }
    ~fraction(){}
    fraction operator+(const fraction& other)const;
    fraction operator-(const fraction& other)const;
    fraction operator*(const fraction& other)const;
    fraction operator/(const fraction& other)const;
    friend ostream& operator <<(ostream& os,fraction& fr);
    friend istream& operator >>(istream& is,fraction& fr);
};

fraction fraction::operator+(const fraction &other)const{
    int up,down;
    up=numerator*other.denominator+denominator*other.numerator;
    down=denominator*other.denominator;
    return fraction{up,down};
}
fraction fraction::operator-(const fraction &other)const{
    int up,down;
    up=numerator*other.denominator-denominator*other.numerator;
    down=denominator*other.denominator;
    return fraction{up,down};
}
fraction fraction::operator*(const fraction &other)const{
    int up,down;
    up=numerator*other.numerator;
    down=denominator*other.denominator;
    return fraction{up,down};
}
fraction fraction::operator/(const fraction &other)const{
    int up,down;
    up=numerator*other.denominator;
    down=denominator*other.numerator;
    return fraction{up,down};
}

ostream& operator <<(ostream& os,fraction& fr){
    if(fr.denominator==1){
        os<<fr.numerator;
        os<<"("<<fixed<<setprecision(6)<<(double)fr.numerator<<")";
        return os;
    }
    os<<fr.numerator<<"/"<<fr.denominator;
    os<<"("<<fixed<<setprecision(6)<<(double)fr.numerator/(double)fr.denominator<<")";
    return os;
}

istream& operator >>(istream& is,fraction& fr){
    int up,down;
    is>>up;
    getchar();
    is>>down;
    fr=fraction{up,down};
    return is;
}

int main(){
    char operator1;
    fraction fr1,fr2,result;
    cin>>fr1;
    cin>>operator1;
    cin>>fr2;
    switch (operator1)
    {
    case '+':result=fr1+fr2;cout<<result<<endl;break;
    case '-':result=fr1-fr2;cout<<result<<endl;break;
    case '*':result=fr1*fr2;cout<<result<<endl;break;
    case '/':result=fr1/fr2;cout<<result<<endl;break;
    default:
        break;
    }

    return 0;
}
