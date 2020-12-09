#include<bits/stdc++.h>
using namespace std;



//链表节点
template<class Elem>
struct Link
{
    Link* prev; // previous link
    Link* next; // next link
    Elem val; // the value
    Link(Elem v):prev(NULL),next(NULL),val(v){}
    Link():prev(NULL),next(NULL),val(0){}
};
//链表
template<class Elem> 
class List {
    Link<Elem>* first; // points to first element
    Link<Elem>* last; // points to one beyond last element
public:
    List() : first(new Link<Elem>()), last(first) {}
    Link<Elem>* begin(){ return first;}
    Link<Elem>* end(){ return last;}

    void push_front(const Elem& v); // insert v at front
    void pop_front(); // remove the first element
    template<class T>
    friend ostream& operator<<(ostream& os ,List<T>& li);
};

template<class Elem> 
void List<Elem>::push_front(const Elem& v){
    Link<Elem>* temp=first;
    first=new Link<Elem>(v);
    first->next=temp;
    temp->prev=first;
}
template<class Elem> 
void List<Elem>::pop_front(){
    if(first!=last){
        Link<Elem>* temp=first;
        first=first->next;
        delete temp;
    }
}
template<class Elem> 
ostream& operator<<(ostream& os ,List<Elem>& li){
    Link<Elem>* it=li.begin();
    while(it!=li.end()){
        os<<it->val<<" ";
        it=it->next;
    }
    return os;
}

int main(){
    List<int> l1;
    for(int i=0;i<=10;i++){
        l1.push_front(i);
    }
    cout<<l1<<endl;
    for(int i=0;i<=2;i++){
        l1.pop_front();
    }
    cout<<l1<<endl;
    return 0;
}