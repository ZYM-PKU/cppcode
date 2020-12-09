#include<bits/stdc++.h>
using namespace std;



int n,d;


bool cmp(pair<double,double>p1,pair<double,double>p2){
    return p1.second <p2.second;//按右节点排序
}
int main(){
    int cases=0;
    while(cin){
        cin>>n>>d;
        cases++;
        if(n==0&&d==0)break;
        bool unable=false;
        vector<pair<double,double>> lines;
        for(int c=1;c<=n;c++){
            int x,y;
            cin >> x >> y;
            if(y>d){unable=true;}//一定要让数据输入进来，否则各个情况之间会相互干扰
            else lines.push_back(make_pair(x-(double)sqrt(pow(d,2)-pow(y,2)),x+(double)sqrt(pow(d,2)-pow(y,2))));
        }
        if(unable){cout<<"Case "<<cases<<": -1"<<endl;continue;}
        sort(lines.begin(),lines.end(),cmp);

        double p=-0xfffff;
        int counting=0;
        for(int i=0;i<lines.size();i++){
            if(p<lines[i].first){
                p=lines[i].second;
                counting++;
            }
        }
        cout<<"Case "<<cases<<": "<<counting<<endl;


    }
    return 0;
}