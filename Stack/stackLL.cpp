#include<iostream>
#include <cstdlib>

using namespace std;


class Node
{
public:
    int data;
    Node *next;
};


class stack{
private:
    Node *top;
public:
    stack();
    ~stack();
    void push(int x);
    int pop();
    void Display();
    int peek(int index);
    int isEmpty();
    int isFull();
    int stackTop();
};

stack::stack(){
    top = nullptr;
}
stack::~stack(){
    Node *p  = top;

    while (top)
    {
        top = top->next;
        delete p;
        p = top;  
    }   
}

void stack::push(int x){
    Node *t = new  Node;

    if (t==nullptr){
        cout<<"Stack is full!!!!\n";
    }
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}
 
int stack::pop(){
    int x = -1;
    Node *p = new Node;
    if (top == nullptr){
        cout<<"Stack is Empty!!!\n";
    }
    else{
        p = top;
        x = top->data;
        top = top->next;

        delete p;
    }

    return x;
}

void stack::Display(){
    Node *p = top;
    while (p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    
}

int stack::isEmpty(){
    return top ? 0 : 1;
}

int stack::isFull(){
    Node* t = new Node;
    int r = t ? 1 : 0;
    delete t;
    return r;
}

int stack::peek(int index){
    
    if (isEmpty()){
        return -1;
    }
    else{
        Node *p = top;
        for(int i=0;p!=nullptr && i<index-1;i++){
            p = p->next; 
        }
        if (p!=nullptr){
            return p->data;
        }
        else{
            return -1;
        }
    }
}

int stack::stackTop(){
    int x=-1;
    if (top==nullptr)
        return x;
    return top->data;
}

int main(){
    int a[] = {1,2,3,4,5,6,7,8,9,10};

    stack stk;

    for(int i=0;i<(sizeof(a)/sizeof(a[0]));i++){
        stk.push(a[i]);
    }

    stk.Display();
    return 0;
}