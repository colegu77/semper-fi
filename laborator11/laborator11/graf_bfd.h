#ifndef GRAF_BFD_H_INCLUDED
#define GRAF_BFD_H_INCLUDED

typedef struct nod_lista{
    enum {white, black, gray} color;
    int d,f;
    int cheie;
    struct nod_lista *next, *prev;
}t_nod_lista;


typedef struct{
    t_nod_lista *head;
}t_lista;

typedef struct{
    t_nod_lista *src, *dest;
    int weight;
}t_edge;

void init_lista(t_lista G[], int n);
void print_lista(t_lista G[], int n);
void print_path(t_lista G[], t_nod_lista *s, t_nod_lista *v);
void insert_vecini(t_lista G[], int ns, int n,t_edge edges[],int *r);
void makenull(t_lista *lista); //trimitem prin referinta lista ca operatia read-write sa fie permanenta
t_nod_lista *list_search(t_lista lista, int k);
void list_insert(t_lista *lista, t_nod_lista *x);
void list_delete(t_lista *lista, t_nod_lista *x);
void list_free(t_lista *lista);
void list_print(t_lista lista);
void quick_sort(t_edge a[], int p, int r);
void initialize_single_source(t_lista G[], t_nod_lista *s, int n);
void relax(t_nod_lista *u, t_nod_lista *v, int w);
int bellman_ford(t_lista G[], t_edge w[], int s, int n, int k);
t_nod_lista* extract_min(t_nod_lista *q[], int n);
int get_weight(t_edge w[], t_nod_lista *u, t_nod_lista *v, int nrarce);
void dijkstra(t_lista G[], t_edge w[], int s, int n, int nrarce);
void relax_d(t_nod_lista *u, t_nod_lista *v, int w, t_nod_lista *q[], int n);

#endif // GRAF_BFD_H_INCLUDED
