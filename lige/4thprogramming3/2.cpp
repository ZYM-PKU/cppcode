#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stdlib.h>

using namespace std;
struct number{
    int num;
    number *next;
};
number *create(int n){
    number *head=new number;
    number *temp=head;
    for(int i=1;i<=n;i++){
        cin>>temp->num;
        if(i<n){
            temp->next=new number;
        temp=temp->next;
        }
        else{
            temp->next=NULL;
        }
    }
    return head;
}
number *deleting(number *head,int a){
    number *temp=head;
    number *follow=head;
    while(temp->next!=NULL){
        if(temp->num==a){
            head=temp->next;
            temp=head;
        }
        else {
            if(temp->next->num==a){
            temp->next=temp->next->next;
        }
        else{
            temp=temp->next;
        }
        }
    }
    return head;

}
int main(){
    int n,k;
    cin>>n;
    number *head;
    head=create(n);
    cin>>k;
    head=deleting(head,k);
    number *temp=head;
    while(temp->next!=NULL){
        cout<<temp->num<<' ';
        temp=temp->next;
    }
    cout<<temp->num<<endl;
   
    return 0;
}