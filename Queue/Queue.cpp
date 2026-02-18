#include<iostream>

using namespace std;

class Queue
{
private:
    int rear;
    int front;
    int size;
    int *Q;
public:
    Queue(){
        front=rear=-1;
        size = 10;
        Q = new int[size];
    };
    Queue(int size){
        front=rear=-1;
        this->size = size;
        Q = new int[this->size];
    };
    void enqueue(int x);
    int dequeue();
    void display();
};

void Queue::enqueue(int x){
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

int Queue::dequeue(){
    int x;
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

int main(){
    Queue q(5);
    q.enqueue(1);
    q.enqueue(5);
    q.enqueue(4);           
    q.enqueue(2);
    q.display();
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    q.display();
    return 0;
}