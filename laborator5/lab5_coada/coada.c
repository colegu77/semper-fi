#include <stdio.h>
#include <stdlib.h>
#include "coada.h"

void init_queue(t_coada *coada, int init_size)
{
    coada->data=(int*)malloc(init_size*sizeof(int));
    coada->head=0;
    coada->tail=0;
    coada->length=0;
}

void free_queue(t_coada *coada)
{
    free(coada->data);
    coada->data=NULL;
    coada->head=-1;
    coada->tail=-1;
}

int queue_empty(t_coada coada)
{
    if(coada.length==0)
        return 1;
    else
        return 0;
}

void enqueue(t_coada *coada, int element)
{
    coada->data[coada->tail]=element;
    coada->length++;
    if(coada->tail==coada->length)
        coada->tail=1;
    else
        coada->tail++;
}


int dequeue(t_coada *coada)
{
    int e=coada->data[coada->head];
    coada->length--;
    if(coada->head==coada->length)
        coada->head=1;
    else
        coada->head++;
    return e;
}

void print_queue(t_coada coada)
{
    int i;
    for(i=coada.head;i<(coada.head+coada.length);i++)
        printf("%d", coada.data[i]);
}
