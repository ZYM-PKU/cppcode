#include<bits/stdc++.h>
using namespace std;

//本例构造了CArray类用于动态申请内存存放可变长的字符序列
template<class T>
class CArray{
    int size;//除去最后一个空字符的字符数
    T *ptr;
public:
    CArray(int s=0);
    CArray(CArray& a);
    CArray(initializer_list<T> lst);
    ~CArray();
    void push_back(T v);
    CArray<T> & operator=(const CArray<T> &a);
    int length(){return size;}
    T& operator[](int i){return ptr[i];}
    template <class T1>
    friend ostream& operator<< (ostream& os,const CArray<T1> & ca);
};

template<class T>
CArray<T>::CArray(int s):size(s){
    if(s==0)ptr=NULL;
    else {
        ptr=new T[s+1];
        memset(ptr,0,sizeof(T)*(s+1));
    }

}
template<class T>
CArray<T>::CArray(CArray<T>& a){
    if(!a.ptr){
        ptr=NULL;size=0;return;
    }
    ptr=new T[a.size+1];
    strcpy(ptr,a.ptr);
    size=a.size;
}
template<class T>
CArray<T>::~CArray(){
    if(ptr)delete[]ptr;
}


template<class T>
CArray<T>& CArray<T>::operator=(const CArray<T> &a){
    if(ptr==a.ptr)return *this;
    if(a.ptr==NULL){
        if(ptr)delete[]ptr;
        ptr=NULL;
        size=0;
        return *this;
    }
    if(size<a.size){
        if(ptr)delete[]ptr;
        ptr=new T[a.size+1];
    }
    strcpy(ptr,a.ptr);
    size=a.size;
    return *this;
}
template<class T>
void CArray<T>::push_back(T v){
    if(ptr){
        if((_msize(ptr)/sizeof(T))<size+2){
            T* temp=new T[2*size+1];//2倍申请内存，提高申请效率
            memset(temp,0,sizeof(T)*(2*size+1));
            strcpy(temp,ptr);
            delete[] ptr;
            ptr=temp;
        }
    }
    else {
        ptr=new T[2];
        memset(ptr,0,sizeof(T)*2);
    }
    ptr[size++]=v;
}

template<class T>
ostream& operator<<(ostream& os,const CArray<T>& ca){
    os<<ca.ptr;
    return os;
}

template<class T>
CArray<T>::CArray(initializer_list<T> lst):size(lst.size()),ptr(new T[size]){
    copy(lst.begin(),lst.end(),ptr);
}

int main(){
    CArray<char> T_array{'a','b','c'};
    while(1){
        char c;
        cin.get(c);
        if(c=='!')break;//程序默认不读入感叹号
        T_array.push_back(c);
    }
    cout<<T_array<<endl;
    CArray<char> b(T_array);
    b.push_back('1');
    T_array=b;
    cout<<T_array;
    
    return 0;
}