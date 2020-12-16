#include<bits/stdc++.h>
using namespace std;

struct Node {
    char val;
    Node* lchild;
    Node* rchild;
    Node(char v){val=v;lchild=NULL;rchild=NULL;}
};

Node* root=new Node('0');
string s;
int t=0;


void build_tree(Node * &root){//替身 (不仅仅传值，还可以更改原指针)
    char curr=s[t++];
	if(curr!='.'){
		root=new Node(curr);
		build_tree(root->lchild);//递归建左子树 
		build_tree(root->rchild);//递归建右子树
	}
	else root=NULL;
}

void inorder(Node* root){
    if(root){
        inorder(root->lchild);
        cout<<root->val;
        inorder(root->rchild);
    }    
}

void backorder(Node* root){
    if(root){
        backorder(root->lchild);
        backorder(root->rchild);
        cout<<root->val;
    }    
}


int main(){
    cin>>s;
    build_tree(root);
    inorder(root);
    cout<<endl;
    backorder(root);
    return 0;
}