#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
using namespace std;
struct Node{
    int num;
    Node *ahead;
    Node *next;
};
Node *Create(int N){
    //包含N个节点的双向循环链表
    int n=1;
    Node *node=new Node;
    node->num=n;
    Node *head=node;
    Node *tail=head;
    while(n++<N){
        node=new Node;
        node->num =n;
        tail->next=node;
        node->ahead=tail;
        tail=tail->next;
    }
    tail->next = head;
    head->ahead=tail;
    return head;
}
Node *Search(Node *head, int P ){
    //从head开始寻找第p个节点,作为起始节点
    while(head->num!=P){
        head=head->next;
        
    }
    return head;
}
Node *Release(Node *head, int M){
    int count=1;
    Node *temp=head;
    while(count<M){
        temp=temp->next;
        count++;
    }
    temp->ahead->next=temp->next;
    temp->next->ahead=temp->ahead;
    head=temp->next;
    delete temp;
    return head;
}
int main(){
    int n,m;
    while(cin>>n>>m){
        if(n==0&&m==0)break;
        Node *head=Create(n);
        while(head->next!=head){
            head=Release(head,m);
        }
        cout<<head->num<<endl;
    }
    return 0;
}