#include <stdlib.h>
#include "tabeladispersie.h"
#include <stdio.h>

void main(void)
{
    t_lista t[100];
    int m, x, k;
    printf("Functia h(x)=x mod m\n");
    printf("Introduceti lungimea tabelei: "); scanf("%d",&m);
    init_hashtable(t,m);
    printf("Dati numere pana la citirea lui 0: ");
    scanf("%d",&x);
    do
    {
        k=chained_hash_insert(t,m,x);
        printf("\nTabela actualizata: ");
        print_hashtable(t,m);
        printf("\n");
        printf("\nDati nr urmator: ");
        scanf("%d", &x);
    }while(x);
    printf("\nElementul cautat este: ");
    scanf("%d",&x);
    k=chained_hash_search(t,m,x);
    printf("\nElement pt stergere: ");
    scanf("%d",&x);
    k=chained_hash_delete(t,m,x);
    print_hashtable(t,m);
}
