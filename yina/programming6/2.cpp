#include<bits/stdc++.h>
using namespace std;


enum Romancharactor{I=1,V=5,X=10,L=50,C=100,D=500}Rc;

class RomanInt{
protected:
    int num;
    string strnum;
public:
    RomanInt():num(0){}
    RomanInt(int _num):num(_num){}
    RomanInt(string _strnum):strnum(_strnum){
        int Inum=0,Vnum=0,Xnum=0,Lnum=0,Cnum=0,Dnum=0;
        for(int i=0;i<strnum.size();i++){
            switch (strnum[i])
            {
            case 'I': {
                if(i!=strnum.size()-1){
                    if(strnum[i+1]=='V'||strnum[i+1]=='X'||strnum[i+1]=='L'||strnum[i+1]=='C'||strnum[i+1]=='D')Inum--;
                    else Inum++;
                }
                else Inum++;
                break;
            }
            case 'X': {
                if(i!=strnum.size()-1){
                    if(strnum[i+1]=='L'||strnum[i+1]=='C'||strnum[i+1]=='D')Xnum--;
                    else Xnum++;
                }
                else Xnum++;
                break;
            }
            case 'C': {
                if(i!=strnum.size()-1){
                    if(strnum[i+1]=='D')Cnum--;
                    else Cnum++;
                }
                else Cnum++;
                break;
            }
            case 'V':Vnum++;break;
            case 'L':Lnum++;break;
            case 'D':Dnum++;break;
            default:
                break;
            }
        }
        num=Inum*I+Vnum*V+Xnum*X+Lnum*L+Cnum*C+Dnum*D;
    }
    friend istream& operator >>(istream& is,RomanInt& ro);
    friend ostream& operator <<(ostream& os,RomanInt& ro);
    RomanInt operator+(RomanInt other){return RomanInt{num+other.num};}
};

istream& operator >>(istream& is,RomanInt& ro){
    string temp;
    is>>temp;
    ro=RomanInt{temp};
    return is;
}

ostream& operator <<(ostream& os,RomanInt& ro){
    os<<ro.num;
    return os;
}

int main(){
    RomanInt ro1,ro2,result;
    cin>>ro1>>ro2;
    result=ro1+ro2;
    cout<<result<<endl;
    return 0;
}