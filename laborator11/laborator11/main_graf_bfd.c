#include <stdlib.h>
#include "graf_bfd.h"
#include <stdio.h>
#include <limits.h>

void main(void)
{
    t_lista G[100];
    int n,i,k=0, nd;
    t_edge edges[100];
    t_edge arc;
    printf("Numar de noduri= ");
    scanf("%d", &n);
    init_lista(G,n);
    for(i=1;i<=n;i++){
        insert_vecini(G,i,n,edges,&k);
    }
    printf("\nLista adiacenta: ");
    print_lista(G,n);
    printf("\nNod de pornire: ");
    scanf("%d", &nd);
    bellman_ford(G,edges,nd,n,k);
    print_path(G,G[nd].head,G[n].head);
    dijkstra(G,edges,nd,n,k);
}
