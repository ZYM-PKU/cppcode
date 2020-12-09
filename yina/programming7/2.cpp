#include<bits/stdc++.h>
using namespace std;

class sentence{
protected:
    string line;
    string processed_line;
public:
    sentence(){}
    ~sentence(){}
    friend istream& operator >>(istream& is,sentence& sen);
    void process();
};

istream& operator >>(istream& is,sentence& sen){
    getline(is,sen.line);
    return is;
}

void sentence::process(){
    for(int i=0;i<line.size();i++){
        switch(line[i]){
            case '.':case ';':case ',':case '?':case '!': {line.replace(i,1," ");i--;break;}
            case '-':{
                if(!(((line[i-1]>='a'&&line[i-1]<='z')||(line[i-1]>='A'&&line[i-1]<='Z'))&&((line[i+1]>='a'&&line[i+1]<='z')||(line[i+1]>='A'&&line[i+1]<='Z')))){
                    line.replace(i,1," ");i--;
                }
                break;
            }
            case '\'':{
                if(line[i-1]=='n'&&line[i+1]=='t'){
                    if(line[i-2]=='a'){
                        line.replace(i,2," not");
                        i+=3;
                    }
                    else if(line[i-2]=='o'){
                        line.replace(i-1,3," not");
                        i+=2;
                    }
                }
            }
        }
    }
    cout<<line<<endl;
}

int main(){
    while(1){
        sentence s;
        if(cin>>s){
            s.process();
        }
        else break;
    }
    return 0;
}