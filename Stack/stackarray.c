#include<stdio.h>
#include<stdlib.h>

struct Stack {
    int size;
    int top;
    int *s;
};

void create(struct Stack *st){
    printf("Enter Size of Stack: ");
    scanf("%d", st->size);

    st->top = -1;
    st->s = (int *) malloc(st->size*sizeof(int));
}

void display(struct Stack n){
    printf("Stack : ");
    for(int i = n.top; i>=0; i--){
        printf("%d ", n.s[i]);
    }
    printf("\n");
}

void push(struct Stack *st,int x){
    if (st->top == st->size-1){
        printf("Stack Overflow.......\n");
    }
    else{
        st->top++;
        st->s[st->top] = x;
    }
}

int pop(struct Stack *st){
    int x = -1;
    if (st->top == -1){
        printf("Stack underflow.......\n");
    }
    else{
        x = st->s[st->top];
        st->top--;
    }

    return x;
}

int peek(struct Stack st, int i){
    int x = -1;

    if (st.top-i+1<0){   
        printf("Invalid Index \n");
    }
    x = st.s[st.top-i+1];
    return x;
}

int isEmpty(struct Stack st){
    if (st.top==-1){
        return 1;
    }

    return 0;
}

int isEmpty(struct Stack st){
    if (st.top==st.size-1){
        return 1;
    }

    return 0;
}

int stackTop(struct Stack st){
    if(!isEmpty(st)){
        return st.s[st.top];
    }
    return -1;
}

int main(){

    struct Stack stack;
    create(&stack);

    push(&stack,10);
    push(&stack,20);
    push(&stack,30);
    push(&stack,40);
    push(&stack,50);

    display(stack);

    return 0;
}