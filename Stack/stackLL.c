#include<stdio.h>
#include<stdlib.h>

struct Node {
    char data;
    struct Node *next;
}*top=NULL;

void push(char x);
char pop();
void Display();
int isBalance(char *exp);

int main(){
    char *exp = "()(()";
    printf("%d\n",isBalance(exp));
    return 0;
}

int isBalance(char *exp){

    for(int i=0 ; exp[i]!='\0' ;i++){
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

void push(char x){
    struct Node *t;

    t = (struct Node *) malloc(sizeof(struct Node));

    if (t == NULL){
        printf("Stack Overflow!!!\n");
    }
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
    
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