#ifndef GRAF_H_INCLUDED
#define GRAF_H_INCLUDED

typedef struct nod_lista{
    enum {white, black, gray} color;
    int d,f;
    int cheie;
    struct nod_lista *next, *prev;
}t_nod_lista;


typedef struct{
    t_nod_lista *head;
}t_lista;

void init_lista(t_lista G[], int n);
void print_lista(t_lista G[], int n);
void print_path(t_lista G[], t_nod_lista *s, t_nod_lista *v);
void enqueue(t_nod_lista *q[], t_nod_lista *s, int r);
t_nod_lista *dequeue(t_nod_lista *q[], int r);
void breadth_first_search(t_lista G[], int s, int n);
void dfs_visit(t_lista G[], t_nod_lista *u, int time);
void depth_first_search(t_lista G[], int n);
void insert_vecini(t_lista G[], int ns, int n);
void makenull(t_lista *lista); //trimitem prin referinta lista ca operatia read-write sa fie permanenta
t_nod_lista *list_search(t_lista lista, int k);
void list_insert(t_lista *lista, t_nod_lista *x);
void list_delete(t_lista *lista, t_nod_lista *x);
void list_free(t_lista *lista);
void list_print(t_lista lista);
void dfs_visit_top(t_lista G[], t_nod_lista *u, int* time, t_lista topo,int n);
t_lista top_sort(t_lista G[], int n);

#endif // GRAF_H_INCLUDED
