#include <stdlib.h>
#include "tabeladispersie.h"
#include <stdio.h>

int hash_function(int x, int m)
{
    return x%m;
}

void init_hashtable(t_lista t[], int m)
{
    int i;
    for(i=0; i<m; i++)
        makenull(&t[i]);
}

int chained_hash_insert(t_lista t[], int m, int x)
{
    t_nod_lista *n;
    int k=hash_function(x,m);
    n=(t_nod_lista*)malloc(sizeof(t_nod_lista));
    n->cheie=x;
    list_insert(&t[k],n);
    return k;
}

int chained_hash_search(t_lista t[], int m, int x)
{
    t_nod_lista *n;
    int k=hash_function(x,m);
    n=list_search(t[k],x);
    if(n!=NULL)
    {
        printf("Gasit pe pozitia %d", k);
        return k;
    }
    else
    {
        printf("Element negasit");
        return -1;
    }
}

int chained_hash_delete(t_lista t[], int m, int x)
{
    t_nod_lista *n;
    int k=hash_function(x,m);
    n=list_search(t[k],x);
    if(n>0)
    {
        printf("Gasit pe pozitia %d", k);
        list_delete(&t[k],n);
        return k;
    }
    else
    {
        printf("Element negasit");
        return -1;
    }
}

void print_hashtable(t_lista t[], int m)
{
    int k;
    for(k=0; k<m; k++)
        if(t[k].head->next!=NULL)
        {
            printf("\nt[%d]:",k);
            list_print(t[k]);
            printf("\n");
        }
}

