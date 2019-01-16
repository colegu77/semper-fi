#include <stdio.h>
#include <stdlib.h>
#include "coada.h"

void main(void)
{
    t_coada coada;
    int size=20, elemcoada,e;
    init_queue(&coada, size);
    printf("Dati nr de elemente din coada: ");
    scanf("%d", &elemcoada);
    while(elemcoada)
    {
        printf("Dati elementul pt inserare in coada: ");
        scanf("%d", &e);
        enqueue(&coada,e);
        print_queue(coada);
        printf("\n");
        elemcoada--;
    }
    while(!queue_empty(coada))
    {
        dequeue(&coada);
        printf("Coada dupa eliminarea unui element: ");
        print_queue(coada);
        printf("\n");
    }
    free_queue(&coada);
}
