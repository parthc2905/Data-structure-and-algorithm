#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n){
    struct Node *t,*last;
    int i;

    first = (struct Node *) malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for( i = 1;i < n; i++){
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }

}

void Display(struct Node *p){
    while (p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}

int length(struct Node *p){
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;        
    }

    return len;
}

void insert(struct Node *p,int index, int n){
    struct Node *t;

    if (index<0 || index>length(first))
        return;

    if(index==0){
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = n;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else{
        for(int i = 0;i<index-1;i++){
            p = p->next;
        }

        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = n;
    
        t->next = p->next;
        t->prev = p;

        if (p->next) p->next->prev = t;

        p->next = t;
        
    }
}

int delete(struct Node *p,int index){
    
    int x=-1,i;

    if (index== 0){
        first = first->next;
        if (first){
            first->prev = NULL;
        }
        x = p->data;
        free(p);
    }
    else{
        for(int i = 0;i<index-1;i++){
            p = p->next;
        }
        p = p->next;

        if (p->next)  p->next->prev = p->prev;
        x = p->data;
        p->prev->next = p->next;

        free(p);
    }   

    return x;
}

void reverse(struct Node *p){
    struct Node *temp;

    while(p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if( p!=NULL && p->next==NULL) 
            first = p;

    }
    
}

int middleEle2loops(struct Node *p){
    for(int i = 0; i<(length(first)/2); i++){
        p = p->next;
    }
    return length(first)%2? p->data:p->prev->data;
}

int middleby1loop(struct Node *p){
    struct Node *q = first;
    while(q){
        q = q->next;
        if (q) q = q->next;
        if (q) p = p->next;
    }

    return p->data;
}

void main(){
    
    int arr[] = {2,5,23,13,6};
    create(arr,5);

    printf("Length of the array: %d\n",length(first));
    Display(first);

    insert(first, 2, 45);
    Display(first);
    int res = delete(first,2);
    printf("%d\n",res);
    Display(first);

    insert(first, 4, 54);
    Display(first);
    printf("%d\n",middleby1loop(first));

    return;
}