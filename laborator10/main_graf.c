
void main(void)
{
    t_lista G[100];
    t_lista topology;
    int n,i,n1,n2;
    printf("Numar de noduri= ");
    scanf("%d", &n);
    init_lista(G,n);
    for(i=1;i<=n;i++)
        insert_vecini(G,n,i);
    printf("\nLista adiacenta: ");
    print_lista(G,n);
    printf("\nParcurgere in latime: ");
    printf("\nNod de start: ");
    scanf("%d", &n1);
    breadth_first_search(G,n1,n);
    printf("\nCalea cea mai scurta: ");
    printf("\nNod de start: ");
    scanf("%d", &n1);
    printf("\nNod de final: ");
    scanf("%d", &n2);
    print_path(G,G[n1].head,G[n2].head);
    printf("\nParcurgere in adancime: ");
    depth_first_search(G,n);
    printf("\nSortare topologica: ");
    topology=top_sort(G,n);
    list_print(topology);
}
