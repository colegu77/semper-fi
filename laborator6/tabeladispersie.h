#ifndef TABELADISPERSIE_H_INCLUDED
#define TABELADISPERSIE_H_INCLUDED
#include "lista.h"

int hash_function(int x, int m);
void init_hashtable(t_lista t[], int m);
int chained_hash_insert(t_lista t[], int m, int x);
void print_hashtable(t_lista t[], int m);
int chained_hash_search(t_lista t[], int m, int x);
int chained_hash_delete(t_lista t[], int m, int x);

#endif // TABELADISPERSIE_H_INCLUDED
