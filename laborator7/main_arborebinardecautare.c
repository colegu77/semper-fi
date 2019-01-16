#include <stdio.h>
#include <stdlib.h>
#include "arbore.h"

void main(void)
{
    t_arbore *t;
    t_nod_arb *n;
    int x;
    printf("Radacina este: ");
    scanf("%d", &x);
    make_root(&t,x);
    printf("\nIntroduceti numere pana la scrierea lui 0: ");
    printf("\n x= "); scanf("%d", &x);
    while(x!=0)
    {
        n=create_node(x);
        tree_insert(&t,n);
        printf("\nx= ");
        scanf("%d", &x);
    }
    printf("\nIn-order walk: ");
    inorder_walk(t);
    printf("\nPre-order walk: ");
    preorder_walk(t);
    printf("\nPost-order walk: ");
    postorder_walk(t);
    printf("\n");
    printf("Regasire nod: ");
    scanf("%d", &x);
    n=iterative_tree_search(&t->root, x);
    if(n!=NULL)
        printf("\nNodul cu cheia %d a fost gasit iterativ.", n->key);
    else
        printf("\nNodul nu a fost gasit iterativ.");
    n=tree_search(&t->root,x);
    if(n!=NULL)
        printf("\nNodul cu cheia %d a fost gasit recursiv.", n->key);
    else
        printf("\nNodul nu a fost gasit recursiv.");
    n=tree_min(&t->root);
    printf("\nTree minimum= %d", n->key);
    n=tree_max(&t->root);
    printf("\nTree maximum= %d", n->key);
    n=tree_successor(&t->root);
    if(n!=NULL)
        printf("\nNod succesor: %d", n->key);
    else
        printf("\nNULL.");
    printf("\nSterge nod cu cheia: ");
    scanf("%d",&x);
    n=tree_search(&t->root,x);
    if(n!=NULL)
    {
        tree_delete(t,n);
        printf("\nNod sters.\n");
        inorder_walk(t);
    }
    else
        printf("\nNod negasit!");


}
