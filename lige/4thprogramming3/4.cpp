#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
struct point{
    int x;
    int y;
    int z;
}points[20];
struct result {
    double distance;
    int lx;
    int ly;
    int lz;
    int rx;
    int ry;
    int rz;
}results[100];
bool cmp(result a,result b){
    return a.distance >b.distance;
}
int main(){
    int n;
    int t=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin >> points[i].x >>points[i].y>>points[i].z;
    }
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            results[t].lx=points[i].x;
            results[t].ly=points[i].y;
            results[t].lz=points[i].z;
            results[t].rx=points[j].x;
            results[t].ry=points[j].y;
            results[t].rz=points[j].z;
            results[t++].distance =sqrt(pow((double)(points[i].x-points[j].x),2.0)+pow((double)(points[i].y-points[j].y),2.0)+pow((double)(points[i].z-points[j].z),2.0));
        }
    }
    sort(results,results+t,cmp);
    for(int i=0;i<t;i++){
        cout<<"("<<results[i].lx<<','<<results[i].ly<<','<<results[i].lz<<')'<<'-'<<"("<<results[i].rx<<','<<results[i].ry<<','<<results[i].rz<<')'<<'='<<fixed<<setprecision(2)<<results[i].distance<<endl;
    }
    return 0;
}