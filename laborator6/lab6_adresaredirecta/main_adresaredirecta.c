#include <stdio.h>
#include <stdlib.h>
#include "adresaredirecta.h"

void main(void)
{
    int t[100], m, x,k;
    printf("Introduceti lungimea tabelei: "); scanf("%d", &m);
    hash_init(t,m);
    printf("Dati numere pana la citirea lui 0: ");
    scanf("%d", &x);
    do{
        k=hash_insert(t,m,x);
        printf("\nElement introdus pe pozitia %d.",k);
        printf("\nDati urmatorul element de inserat: ");
        scanf("%d", &x);
    }while(x);
    printf("\nTabela actuala este: ");
    hash_print(t,m);
    printf("\n Cautare element: ");
    scanf("%d", &x);
    k=hash_search(t,m,x);
    if(k>-1)
        printf("\nElement gasit pe pozitia %d",k);
    else
        printf("\nElementul nu a fost gasit.");
    printf("\nStergere element: ");
    scanf("%d", &x);
    k=hash_delete(t,m,x);
    if(k>-1)
    {
        printf("\nElement sters de pe pozitia %d",k);
        printf("\nNoua tabela actualizata: ");
        hash_print(t,m);
    }
    else
        printf("\n Elementul nu a fost gasit.");
}
