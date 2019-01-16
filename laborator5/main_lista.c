#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void main()
{
    t_lista lista;
    t_nod_lista *x;
    char selectie=1;
    int k;
    makenull(&lista);
        printf("1 pentru cautare in lista \n");
        printf("2 pentru inserare in lista \n");
        printf("3 pentru stergere din lista \n");
        printf("4 pentru afisarea listei \n");
        printf("0 pentru iesire \n");


    while(selectie){
    printf("Introduceti optiunea dumneavoastra: ");
    scanf("%c", &selectie);
    switch(selectie)
    {
    case '0': {break;}
    case '1':
    {
        printf("Introduceti cheia de cautare: ");
        scanf("%d ", &k);
        x=list_search(lista, k);
        if(x)
            printf("Cheia %d a fost gasita la adresa %d.\n", k, x);
        else
            printf("Cheia %d nu a fost gasita.\n", k);
        break;
    }
    case '2':
        {
            printf("Introduceti cheia care se insereaza: ");
            scanf("%d", &k);
            x=(t_nod_lista*)malloc(sizeof(t_nod_lista));
            x->cheie=k;
            list_insert(&lista, x);
            break;
        }
    case '3':
        {
            printf("Introduceti cheia care se sterge: ");
            scanf("%d", &k);
            x=list_search(lista, k);
            if(x)
                list_delete(&lista, x);
            else
                printf("Cheia %d nu a fost gasita.\n", k);
            break;
        }
    case '4':
        {
            list_print(lista);
            break;
        }
    }
    }
    list_free(&lista);
}
