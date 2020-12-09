#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <string>

#define random(x) (rand() % x)

using namespace std;

int sum=0;

class wind
{
private:
    string name;
public:
    void setname(string str)
    {
        name = str;
        sum++;
    }
    wind() {}
    wind(string str) : name(str) {}
    friend std::ostream &operator<<(ostream &o, wind &w);
};

class normalcard
{
private:
    string name;
    int number;

public:
    normalcard() {}
    normalcard(int n, string str) : number(n), name(str) {}
    void initial(int n, string str)
    {
        name = str;
        number = n;
        sum++;
    }
    friend std::ostream &operator<<(ostream &o, normalcard &n);
};

class mahjong
{
private:
    wind w[4], e[4], n[4], s[4], f[4], b[4], z[4];
    normalcard bing[9][4], tiao[9][4], wan[9][4];
public:
    mahjong()
    {
        for (int i = 0; i < 4; i++)
        {
            w[i].setname("西");
            e[i].setname("东");
            n[i].setname("北");
            s[i].setname("南");
            f[i].setname("發");
            b[i].setname("白");
            z[i].setname("中");
        }
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                bing[i][j].initial(i + 1, "饼");
                tiao[i][j].initial(i + 1, "条");
                wan[i][j].initial(i + 1, "萬");
            }
        }
    }
    void printm(){
        for(int i=0;i<4;i++)cout<<w[i]<<" ";
        cout<<endl;
        for(int i=0;i<4;i++)cout<<e[i]<<" ";
        cout<<endl;
        for(int i=0;i<4;i++)cout<<n[i]<<" ";
        cout<<endl;
        for(int i=0;i<4;i++)cout<<s[i]<<" ";
        cout<<endl;
        for(int i=0;i<4;i++)cout<<f[i]<<" ";
        cout<<endl;
        for(int i=0;i<4;i++)cout<<b[i]<<" ";
        cout<<endl;
        for(int i=0;i<4;i++)cout<<z[i]<<" ";
        cout<<endl;
        for(int j=0;j<4;j++){
            for(int i=0;i<9;i++){
                cout<<bing[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int j=0;j<4;j++){
            for(int i=0;i<9;i++){
                cout<<tiao[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int j=0;j<4;j++){
            for(int i=0;i<9;i++){
                cout<<wan[i][j]<<" ";
            }
            cout<<endl;
        }

    }
};

ostream &operator<<(ostream &o, wind &w)
{ //重载wind类的输出
    o << w.name;
    return o;
}
ostream &operator<<(ostream &o, normalcard &n)
{ //重载wind类的输出
    o << n.number << n.name;
    return o;
}

int main()
{
    srand((int)time(0)); //生成随机种子
    mahjong mymahjong;
    mymahjong.printm();
    return 0;
}