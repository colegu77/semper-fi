#include <stdio.h>
#include <stdlib.h>
#include "adresaredirecta.h"

void hash_init(int t[], int m)
{
    int i;
    for(i=0;i<m;i++)
        t[i]=-1;
}

int hash_prim(int m, int k)
{
    return k%m;
}

int hash_probef(int k, int i, int m)
{
    return(hash_prim(m,k)+i)%m;
}

int hash_insert(int t[], int m, int k)
{
    int i=0, j;
    do{
        j=hash_probef(k,i,m);
        if(t[j]==-1)
        {
            t[j]=k;
            return j;
        }
        else
            i++;
    }while(i!=m);
    return -1;
}

int hash_search(int t[], int m, int k)
{
    int i=0, j;
    do{
        j=hash_probef(k,i,m);
        if(t[j]==k)
            return j;
        i++;
    }while((i!=m)&&(t[j]!=m));
    return -1;
}

int hash_delete(int t[], int m, int k)
{
    int j;
    j=hash_search(t,m,k);
    if(j>-1)
    {
        t[j]=-1;
        return j;
    }
    else
        return -1;
}

void hash_print(int t[], int m)
{
    int i=0;
    for(i=0;i<m;i++)
        printf("t[%d]= %d", i, t[i]);
}
