#include<bits/stdc++.h>
#define INFINITY 2
using namespace std;


map<string,int>p;//字符串整数映射
string rp[100];//逆映射



int main(){
    
    int P;
    cin>>P;
    int matrix[P][P]={0};
    int track[P][P]={0};
    memset(matrix,INFINITY,sizeof(matrix));
    memset(track,-1,sizeof(track));
    for(int i=0;i<P;i++){
        string str;
        cin>>str;
        p[str]=i;
        rp[i]=str;
        matrix[i][i]=0;
        track[i][i]=i;
    }

    int Q;
    cin>>Q;
    for(int i=0;i<Q;i++){
        int dis;
        string place1,place2;
        cin>>place1>>place2>>dis;
        matrix[p[place1]][p[place2]]=matrix[p[place2]][p[place1]]=min(dis,matrix[p[place1]][p[place2]]);
        track[p[place1]][p[place2]]=p[place1];
        track[p[place2]][p[place1]]=p[place2];
    }

     
    for(int k=0;k<P;k++)//Floyd
    for(int i=0;i<P;i++)
    for(int j=0;j<P;j++){
        if (matrix[i][k]+matrix[k][j]<matrix[i][j]){
            matrix[i][j]=matrix[i][k]+matrix[k][j];
            track[i][j]=track[k][j];
        }
    }

    int R;
    cin>>R;
    for(int i=0;i<R;i++){
        string place1,place2;
        cin>>place1>>place2;
        int temp=p[place2];
        int prev=track[p[place1]][p[place2]];
        stack<int>rstack;//使用栈输出路径
        rstack.push(temp);
        while(temp!=p[place1]){
            rstack.push(matrix[prev][temp]);
            rstack.push(prev);
            temp=prev;
            prev=track[p[place1]][prev];
        }
        int c=0;
        while(!rstack.empty()){
            if(c%2==0){
                cout<<rp[rstack.top()];
            }
            else{
                cout<<"->("<<rstack.top()<<")->";
            }
            rstack.pop();
            c++;
        }
        cout<<endl;
    }

    return 0;
}