include<bits/stdc++.h>
using namespace std;

struct Node {
    char val;
    Node* leftchild;
    Node* rightchild;
    Node* father;
    Node(char v){val=v;leftchild=NULL,rightchild=NULL;}
}


enum FLAG{
    left=0;
    right=1;
}

int main(){
    string str;
    cin>>str;
    Node* root=new Node(str[0]);
    int size=str.size();
    FLAG flag = left;
    Node* temp=root;
    for(int i=1;i<size;i++){
        char curr = str[i];
        if(flag == left){
            


        }

    }


    return 0;
}