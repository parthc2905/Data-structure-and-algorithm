#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>
struct Node *root = NULL;


void treeCreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);
    root = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter root value: ");
    scanf("%d", &x);
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d: ",p->data);
        scanf("%d", &x);    
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d: ",p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main()
{
    treeCreate();

    preorder(root);
    return 0;
}