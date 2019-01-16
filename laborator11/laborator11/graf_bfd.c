#include <stdlib.h>
#include "graf_bfd.h"
#include <stdio.h>
#include <limits.h>

void init_lista(t_lista G[], int n)
{
    int i;
    for(i=1;i<=n;i++)
        makenull(&G[i]);
}

void print_lista(t_lista G[], int n)
{
    t_nod_lista *nod;
    int i;
    for(i=1;i<=n;i++)
    {
        nod=G[i].head->next;
        printf("%d: ",i);
        while(nod!=NULL)
        {
            printf("%d", nod->cheie);
            nod=nod->next;
        }
        printf("\n");
    }
}

void print_path(t_lista G[], t_nod_lista *s, t_nod_lista *v)
{
    if(v==s)
        printf("%d",s->cheie);
    else
    {
        if(v->prev==NULL)
            printf("Nu exista cale.");
        else
        {
            print_path(G,s,v->prev);
            printf("%d",v->cheie);
        }
    }
}

void makenull(t_lista *lista)
{
    lista->head=(t_nod_lista *)malloc(sizeof(t_nod_lista));
    lista->head->next=lista->head->prev=NULL;
}

void insert_vecini(t_lista G[], int ns, int n,t_edge edges[],int *r)
{
    t_nod_lista *nod;
    t_edge e;
    int w,nv;
    printf("Nod sursa %d: ", ns);
    G[ns].head->cheie=ns;
    printf("\nDati vecinii nodului sursa: ");
    do
    {
        printf("Vecin cu %d: ", ns);
        scanf("%d", &nv);
        if((nv>0) && (nv<=n) && (nv!=ns))
        {
            nod=(t_nod_lista*)malloc(sizeof(t_nod_lista));
            nod->cheie=nv;
            list_insert(&G[ns], nod);
            printf("Introduceti weight pentru arcul %d-%d: ",ns,nv);
            scanf("%d",&w);
            e.weight=w;
            e.src=G[ns].head;
            e.dest=nod;
            (*r)++;
            edges[*r]=e;
        }
    }while(nv>0);
}
t_nod_lista *list_search(t_lista lista, int k)
{
    t_nod_lista *x=lista.head->next;
    while(x && (x->cheie!=k))
        x=x->next;
    return x;
}

void list_insert(t_lista *lista, t_nod_lista *x)
{
    if(x==NULL)
        return;
    x->next=lista->head->next; //x va deveni primul elem din lista si urmatorul lui x va fi primul actual
    if(lista->head->next!=NULL) //daca lista nu e vida
        lista->head->next->prev=x; //precedentul primului actual va fi noul x pe care il inseram pe prima pozitie
    lista->head->next=x; //ii spune lui x ca urmeaza dupa santinela
    x->prev=lista->head; // ii spune lui x ca in urma lui e santinela
}

void list_delete(t_lista *lista, t_nod_lista *x)
{
    if(x==NULL)
        return;
    if(x->prev!=NULL) // daca x nu e primul element
        x->prev->next=x->next; //  urmatorul precedentului va fi urmatorul elementului pe care il stergem
    else
        lista->head=x->next; // noua santinela va fi elementul care era in fata lui x pe care il stergem
    if(x->next!=NULL) // daca x nu e ultimul element
        x->next->prev=x->prev; // precedentul urmatorului va fi anteriorul elementului pe care il stergem
    // x mai e in memorie pt ca nu l-am dezalocat cu free
}

void list_print(t_lista lista)
{
    t_nod_lista *x=lista.head->next;
    if(x==NULL)
        printf("Lista vida.\n");
    else
        while(x) // sau for(; x; x=x->next) printf("%d ", x->cheie);
        {
            printf("%d", x->cheie);
            x=x->next;
        }
}

void list_free(t_lista *lista) //sterge lista si elibereaza zona de memorie
{
    t_nod_lista *x=lista->head->next;
    while(x)
    {
        list_delete(lista, x);
        free(x);
        x=lista->head->next;
    }
    free(lista->head);
}


void initialize_single_source(t_lista G[], t_nod_lista *s, int n)
{
    t_nod_lista *u;
    int i;
    for(i=1;i<=n;i++)
    {
        u=G[i].head;
        u->d=INT_MAX;
        u->prev=NULL;
    }
    s->d=0;
}

void relax_d(t_nod_lista *u, t_nod_lista *v, int w, t_nod_lista *q[], int n)
{
    int i;
    if(v->d>(u->d+w))
    {
        v->d=u->d+w;
        for(i=1;i<=n;i++)
            if(q[i]->cheie==v->cheie)
                q[i]->d=u->d+w;
        v->prev=u;
    }
}

void relax(t_nod_lista *u, t_nod_lista *v, int w)
{
    if(v->d>(u->d+w))
       {
           v->d=u->d+w;
           v->prev=u;
       }
}

int bellman_ford(t_lista G[], t_edge w[], int s, int n, int k)
{
    int i;
    t_nod_lista *ns;
    ns=G[s].head;
    initialize_single_source(G,ns,n);
    for(i=1;i<=n-1;i++)
        relax(G[w[i].src->cheie].head, G[w[i].dest->cheie].head, w[i].weight);
    for(i=1;i<=k;i++)
        if(G[w[i].dest->cheie].head->d >(G[w[i].src->cheie].head->d+w[i].weight))
            return 0;
    return 1;
}

t_nod_lista* extract_min(t_nod_lista *q[], int n)
{
    int i, j, min=INT_MAX;
    t_nod_lista *u;
    for(i=1;i<=n;i++)
        if(q[i]->d<min)
        {
            min=q[i]->d;
            u=q[i];
            j=i;
        }
    for(i=j;i<n;i++)
        q[i]=q[i+1];
    return u;
}

int get_weight(t_edge w[], t_nod_lista *u, t_nod_lista *v, int nrarce)
{
    int i;
    for(i=1;i<=nrarce;i++)
        if((w[i].src->cheie==u->cheie)&&(w[i].dest->cheie==v->cheie))
            return w[i].weight;

}

void dijkstra(t_lista G[], t_edge w[], int s, int n, int nrarce)
{
    t_nod_lista *ss[100], *q[100], *u, *ns, *v;
    int i, l=0, weight=0;
    ns=G[s].head;
    initialize_single_source(G, ns, n);
    for(i=1;i<=n;i++)
        q[i]=G[i].head;
    while(n>0)
    {
        u=extract_min(q,n);
        n--;
        l++;
        ss[l]=u;
        v=G[u->cheie].head;
        while(v!=NULL)
        {
            weight=get_weight(w,u,v,nrarce);
            relax_d(G[u->cheie].head,G[v->cheie].head,weight,q, n);
            v=v->next;
        }
    }

    printf("\nl= %d", l);
    printf("\nDijkstra: ");
    for(i=1;i<=l;i++)
        printf("%d", ss[i]->cheie);
}

