#include<bits/stdc++.h>
using namespace std;

vector<int>weight{2,3,4};

struct student{
    string id;
    double average;
    vector<int> scores;
    void get_average(){
        average=inner_product(scores.begin(),scores.end(),weight.begin(),0.0)/accumulate(weight.begin(),weight.end(),0.0);

    }
    bool operator<(student& s){return average>s.average;}
    friend ostream& operator<<(ostream& os,student& stu);
    friend istream& operator>>(istream& is,student& stu);
};

vector<student>students;
ostream& operator<<(ostream& os,student& stu){
    os<<stu.id<<" "<<stu.average;
    for(auto score:stu.scores){
        cout<<" "<<score;
    }
    return os;
}
istream& operator>>(istream& is,student& stu){
    is>>stu.id;
    for(int i=0;i<3;i++){
        int score;
        cin>>score;
        stu.scores.push_back(score);
    }
    stu.get_average();
    return is;
}
int main(){
    while(cin){
        student stu;
        cin>>stu;
        if(stu.id.length())students.push_back(stu);
    }
    sort(students.begin(),students.end());
    for(auto stu:students){
        cout<<stu<<endl;
    }

    return 0;
}