#include <stdio.h>
#include <stdlib.h>
#include "stiva.h"

void main(void)
{
    t_stiva stiva;
    int size=20;
    init_stack(&stiva, size);
    int elem=10;
    while(elem)
    {
        push(&stiva, elem);
        elem--;
    }
    printf("Stiva dupa inserarea elementelor: ");
    print_stack(stiva);
    printf("\n");
    while(!stack_empty(stiva))
    {
        pop(&stiva);
        print_stack(stiva);
        printf("\n");
    }
    free_stack(&stiva);
}
