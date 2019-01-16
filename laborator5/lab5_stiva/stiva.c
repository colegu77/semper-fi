#include <stdlib.h>
#include "stiva.h"
#include <stdio.h>

void init_stack(t_stiva *stiva, int init_size)
{
    stiva->data=(int*)malloc(init_size*sizeof(int));
    stiva->top=0;
}

void free_stack(t_stiva *stiva)
{
    free(stiva->data);
    stiva->data=NULL;
    stiva->top=-1;
}

int stack_empty(t_stiva stiva)
{
    if(stiva.top==0)
        return 1;
    else
        return 0;
}

void print_stack(t_stiva stiva)
{
    int i;
    for(i=1;i<=stiva.top;i++)
        printf("%d ", stiva.data[i]);
}

void pop(t_stiva *stiva)
{
    if(stack_empty(*stiva))
    {
        printf("Stiva vida.");
        return -1;
    }
    else
    {
        int element=stiva->data[stiva->top];
        stiva->data[stiva->top]=0;
        stiva->top--;
        return element;
    }
}

void push(t_stiva *stiva, int k)
{
    stiva->top++;
    stiva->data[stiva->top]=k;
}
