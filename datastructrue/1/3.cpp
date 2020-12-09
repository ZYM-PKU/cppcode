#include<bits/stdc++.h>
using namespace std;

template <class T>
struct BinaryTreeNode {
    T val;
    BinaryTreeNode *leftchild;
    BinaryTreeNode *rightchild;
    BinaryTreeNode(T x) : val(x), leftchild(NULL), rightchild(NULL) {}
};


template <class T>
struct BinaryTree {
    BinaryTreeNode<T> *root;
    void InOrderWithoutRecursion(BinaryTreeNode<T> *root);
};

enum Tags{Left, Right};

template <class T>
class StackElement //栈元素定义
{
public:
    BinaryTreeNode<T> *pointer;
    Tags tag;
};

template <class T>
void Visit(BinaryTreeNode<T> * a){
    cout<<a->val<<endl;
}

template <class T>
void BinaryTree<T>::InOrderWithoutRecursion(BinaryTreeNode<T> *root)
{
    using std::stack;
    StackElement<T> element;
    stack<StackElement<T> > aStack;
    BinaryTreeNode<T> *pointer = root;
    do
    {
        while(pointer != NULL)
        {
            element.pointer = pointer;
            element.tag = Left;//1
            aStack.push(element);
            pointer = pointer->leftchild;
        }
        while (!aStack.empty() && aStack.top().tag==Right)aStack.pop();
        if (!aStack.empty() && aStack.top().tag == Left)
        {
            Visit(aStack.top().pointer);
            pointer=aStack.top().pointer->rightchild;
            aStack.top().tag = Right;
        }
    }
    while(!aStack.empty());
}

int main(){
    BinaryTreeNode<int> root(0),n1(1),n2(2),n3(3),n4(4),n5(5);
    root.leftchild=&n1;
    root.rightchild=&n2;
    n1.leftchild=&n3;
    n1.rightchild=&n4;
    n3.leftchild=&n5;
    
    BinaryTree<int> t;
    t.InOrderWithoutRecursion(&root);

    
}