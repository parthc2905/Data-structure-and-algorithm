#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node *next;
}*top=NULL;

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
int isOperand(char c){
    if( c == '+' || c == '-' || c== '/' || c== '*'){
        return 0;
    }
    else{
        return 1;
    }
}

int pre(char c){
    if (c=='+' || c=='-'){
        return 1;
    }
    else if (c == '/' || c=='*')
    {
        return 2;
    }
    return 0;
    
}

char * inToPost(char *infix){

    int i = 0, j = 0;
    char *postfix;
    long len = strlen(infix);
    postfix = (char *) malloc((len+2)*sizeof(char));

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else{
            if( pre(infix[i]) >pre(top->data)){
                push(infix[i++]);
            }
            else{
                postfix[j++] = pop();
            }
        }
    }
    while (top)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    
    return postfix;
}






int main(){
    
    char *infix = "a+b*c";

    push('#');
    char *postfix = inToPost(infix) ;
    printf("%s\n",postfix);
    return 0;
}