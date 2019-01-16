#include <stdlib.h>
#include "graf.h"
#include <stdio.h>
#include <limits.h>

void makenull(t_lista *lista)
{
    lista->head=(t_nod_lista *)malloc(sizeof(t_nod_lista));
    lista->head->next=lista->head->prev=NULL;
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

void enqueue(t_nod_lista *q[], t_nod_lista *s, int r)
{
        r++;
        q[r]=s;
}

t_nod_lista *dequeue(t_nod_lista *q[], int r)
{
    t_nod_lista *u=q[0];
    int i;
    for(i=0;i<r;i++)
        q[i]=q[i+1];
    r--;
    return u;
}

void breadth_first_search(t_lista G[], int s, int n)
{
    t_nod_lista *q[100], *u, *v,*ns;
    int i, k;
    for(i=1;i<=n;i++)
    {
        u=G[i].head;
        while(u!=NULL)
        {
        if(u->cheie!=s)
        {
            u->color=white;
            u->d=INT_MAX;
            u->prev=NULL;
        }
        u=u->next;
        }
    }
    ns=G[s].head->next;

    ns->color=gray;
    ns->d=0;
    ns->prev=NULL;
    k=1;
	q[k]=ns;
	while (k>0)
	{
		u=q[1];
		for (i=1;i<k;i++)
		    q[i]=q[i+1];
		k--;
		  v=G[u->cheie].head;
		  while (v!=NULL)
		  {
		  	if (v->color==white)
		  	{

		  		v->color=gray;
		  		v->d=u->d+1;
		  		v->prev=u;
		  		k++;
		  		q[k]=v;
			  }
		  	v=v->next;
		  }
		  u->color=black;
		  printf("%d",u->cheie);

	}

}

void dfs_visit(t_lista G[], t_nod_lista *u, int time)
{
    time++;
    u->d=time;
    u->color=gray;
    t_nod_lista *v;
    v=G[u->cheie].head->next;
    while(v!=NULL){
        if(v->color==white)
    {
        v->prev=u;
        printf("%d",v->cheie);
        dfs_visit(G,v,time);
    }
    v=v->next;
    }
    u->color=black;
    time++;
    u->f=time;
}

void depth_first_search(t_lista G[], int n)
{
    int time, i;
    t_nod_lista *u;
    for(i=1;i<=n;i++)
    {
        u=G[i].head;
        while(u!=NULL){
        u->color=white;
        u->prev=NULL;
        u=u->next;
        }
    }
    time=0;
    for(i=1;i<=n;i++)
    {
        u=G[i].head;
        while(u!=NULL){
        if(u->color==white)
            {dfs_visit(G,u,time);
            u=u->next;}
        }
    }
}

void insert_vecini(t_lista G[], int n, int ns)
{
    t_nod_lista *nod;
    int nv;
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
        }
    }while(nv>0);
}

void dfs_visit_top(t_lista G[], t_nod_lista *u, int *time, t_lista topo, int n)
{
    (*time)++;
    u->d=*time;
    u->color=gray;
    t_nod_lista *v;
    v=G[u->cheie].head;
    while(v!=NULL){
        if(v->color==white)
    {
        v->prev=u;
        dfs_visit_top(G,v,time,topo,n);
    }
    v=v->next;
    }
    u->color=black;
    (*time)++;
    u->f=*time;
    list_insert(&topo,u);
}

t_lista top_sort(t_lista G[], int n)
{
    int i,time;
    t_lista topo;
    makenull(&topo);
    t_nod_lista *u;
    for(i=1;i<=n;i++)
    {
        u=G[i].head;
        while(u!=NULL){
        u->color=white;
        u->prev=NULL;
        u=u->next;}
    }
    time=0;
    for(i=1;i<=n;i++)
    {
        u=G[i].head;
        while(u!=NULL){
        if(u->color==white)
            dfs_visit_top(G,u,&time,topo,n);
        u=u->next;}
    }
    return topo;
}

