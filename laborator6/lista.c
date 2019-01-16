#include <stdlib.h>
#include "lista.h"
#include <stdio.h>

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

