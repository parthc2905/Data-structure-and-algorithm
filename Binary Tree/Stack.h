#include<stdio.h>
#include<stdlib.h>

#ifndef Stack_h
#define Stack_h

struct Stack {
    int size;
    int top;
    struct Stack **S;   
};


void Stackcreate(struct Stack *st, int size){
    st->size = size;
    st->top = -1;
    st->S = (struct Stack **) malloc(st->size*sizeof(struct Stack *));
}

int isBalance(char *exp){

    for(int i=0 ; exp[i]!='\0' ; i++){
        if ( exp[i]=='(' ){
            push(exp[i]);
        }
        else if(exp[i]== ')' ){
            if (top==NULL) return 0;
            pop();
        }
    }
    return top==NULL? 1:0;
}

void push(struct Stack *st,struct Stack *x){
    // struct Node *t;

    // if(st-)
    
}


char pop(){
    char x ;
    struct Node *t;
    if (top==NULL){
        printf("Stack is Empty!!!\n");
    }
    else{
        t = top;
        x = top->data;
        top = top->next;
        free(t);
    }

    return x;
}

void Display(){
    struct Node *t = top;
    while(t){
        printf("%d ",t->data);
        t = t->next;
    }
    printf("\n");

}

#endif