#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

#define random(x) (rand() % x)

using namespace std;

int main()
{
    srand((int)time(0)); //生成随机种子
    int cardface[37] = {0};
    int num = 1;
    for (int i = 1; i <= 36; i++)
    {
        cardface[i] = num;
        num++;
        if (num == 10)
            num = 1;
    }
    int mycard[2] = {0};
    int counting=0;
    int cardcount[10]={0};
    while (1)
    {
        mycard[0] = cardface[random(36)+1];
        mycard[1] = cardface[random(36)+1];

        if(mycard[0]==mycard[1]){
            cout<<"simulating case "<<counting++<<" : "<<mycard[0]<<" "<<mycard[1]<<"  needed card: "<<mycard[0]<<endl;
            cardcount[mycard[0]]++;
        }
        else if(abs(mycard[1]-mycard[0])==1){
            cout<<"simulating case "<<counting++<<" : "<<mycard[0]<<" "<<mycard[1]<<"  needed card: "<<min(mycard[0],mycard[1])-1<<" "<<max(mycard[0],mycard[1])+1<<endl;
            cardcount[min(mycard[0],mycard[1])-1]++;
            cardcount[max(mycard[0],mycard[1])+1]++;
        }
        else if(abs(mycard[1]-mycard[0])==2){
            cout<<"simulating case "<<counting++<<" : "<<mycard[0]<<" "<<mycard[1]<<"  needed card: "<<min(mycard[0],mycard[1])+1<<endl;
            cardcount[min(mycard[0],mycard[1])+1]++;
        }
        if(counting==200000)break;
    }
    cout<<endl;
    cout<<endl;
    cout<<"---------------------------------------"<<endl;cout<<endl;
    cout<<"simulation result:"<<endl;
    for(int i=1;i<=9;i++){
        cout<<"need "<<i<<" card: "<<cardcount[i]<<" pieces."<<endl;
    }

    return 0;
}