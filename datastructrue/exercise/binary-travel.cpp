#include<bits/stdc++.h>

using namespace std;

int N;
int print_count=0;

struct Node{
    int data;
    int id;
    int lchild;
    int rchild;
}Tree[2000];

void preorder(Node n){
    cout<<n.id;
    if(++print_count<N)cout<<" ";
    if (n.lchild!=-1)preorder(Tree[n.lchild]);
    if (n.rchild!=-1)preorder(Tree[n.rchild]);
}

void inorder(Node n){
    if (n.lchild!=-1)inorder(Tree[n.lchild]);
    cout<<n.id;
    if(++print_count<N)cout<<" ";
    if (n.rchild!=-1)inorder(Tree[n.rchild]);
}

void backorder(Node n){
    if (n.lchild!=-1)backorder(Tree[n.lchild]);
    if (n.rchild!=-1)backorder(Tree[n.rchild]);
    cout<<n.id;
    if(++print_count<N)cout<<" ";
}




int main(){
    cin>>N;
    for (int i=0;i<N;i++){
        Node n;
        int a,b,c;
        cin>>a>>b>>c;
        n.id=a;
        n.lchild=b;
        n.rchild=c;
        Tree[a]=n;
    }
    preorder(Tree[1]);cout<<endl;print_count=0;
    inorder(Tree[1]);cout<<endl;print_count=0;
    backorder(Tree[1]);cout<<endl;print_count=0;
    preorder(Tree[1]);cout<<endl;print_count=0;
    return 0;
}