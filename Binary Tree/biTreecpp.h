#include<iostream>
#include<stdio.h>

#ifndef biTreecpp_h
#define biTreecpp_h

using namespace std;

class Node {
    public:
        Node *lchild;
        int data;
        Node *rchild;

};

class Queue
{
private:
    int rear;
    int front;
    int size;
    Node **Q;
public:
    Queue(){
        front=rear=-1;
        size = 10;
        Q = new Node*[size];
    };
    Queue(int size){
        front=rear=-1;
        this->size = size;
        Q = new Node*[this->size];
    };
    void enqueue(Node * x);
    Node * dequeue();
    void display();
};

void Queue::enqueue(Node * x){
    if(rear==size-1){
        printf("Queue is Full!!!\n");
    }
    else{
        if(front==-1){
            front++;
        }
        rear++;
        Q[rear] = x;
    }
}

Node * Queue::dequeue(){
    Node * x = NULL;
    if( front==rear){
        printf("Queue is Empty!!!\n");
    }
    else{
        x = Q[front];
        front++;
    }
    return x;
}

void Queue::display(){
    for(int i = front;i<=rear;i++){
        printf("%d ",Q[i]);
    }
    printf("\n");
}


#endif
