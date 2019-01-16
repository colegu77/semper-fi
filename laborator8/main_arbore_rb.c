#include <stdio.h>
#include <stdlib.h>
#include "arbore_rb.h"

void main(void)
{
    t_rb_arbore *t;
    t_rb_node *n;
    int x;
    printf("ROOT= ");
    scanf("%d", &x);
    make_root(&t,x);
    printf("\nIntroduceti numere pana la scrierea lui 0: ");
    printf("\n x= "); scanf("%d", &x);
    while(x!=0)
    {
        n=create_node(x);
        rb_insert(&t,n);
        printf("\nIn-order walk intermediar: ");
        inorder_walk(t);
        printf("\nx= ");
        scanf("%d", &x);
    }
    printf("\nIn-order walk: ");
    inorder_walk(t);
    printf("\n");
    printf("\nRegasire nod x= ");
    scanf("%d", &x);
    n=tree_search(&t->root,x);
    if(n!=NULL)
        printf("\nNodul cu cheia %d a fost gasit.", n->key);
    else
        printf("\nNodul nu a fost gasit.");
}
