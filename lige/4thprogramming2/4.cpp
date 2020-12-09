#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstring>
using namespace std;
int maxs;
int row,col;
int matrix[150][150]={0};
void check(int startx,int starty){
    int s=1;
    int temp=1;
    for(int i=startx;i<row;i++){
        if(matrix[i][starty]!=0)break;
        for(int j=starty;j<col;j++){
            if(matrix[i][j]!=0||j==col-1){
                temp=(i-startx+1)*(j-starty);
                s=max(s,temp);
                break;
            }
        }
    }
    maxs=max(maxs,s);
}
int main(){
    cin>>row>>col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix[i][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]==0){
                check(i,j);
            }
        }
    }
    cout<<maxs<<endl;
    return 0;
}