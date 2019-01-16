#ifndef ADRESAREDIRECTA_H_INCLUDED
#define ADRESAREDIRECTA_H_INCLUDED

void hash_init(int t[], int m);
int hash_prim(int m, int k);
int hash_probef(int k, int i, int m);
int hash_insert(int t[], int m, int k);
int hash_search(int t[], int m, int k);
int hash_delete(int t[], int m, int k);
void hash_print(int t[], int m);

#endif // ADRESAREDIRECTA_H_INCLUDED
