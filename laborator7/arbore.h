#ifndef ARBORE_H_INCLUDED
#define ARBORE_H_INCLUDED

typedef struct nod_arb{
    int key;
    struct nod_arb *left, *right, *parent;
}t_nod_arb;

typedef struct{
    t_nod_arb *root;
}t_arbore;

void make_root(t_arbore *arbore, int key);
t_nod_arb *create_node(int key);
void preorder_walk(t_nod_arb *root);
void postorder_walk(t_nod_arb *root);
void inorder_walk(t_nod_arb *root);
t_nod_arb *tree_min(t_nod_arb *n);
t_nod_arb *tree_max(t_nod_arb *n);
t_nod_arb *tree_successor(t_nod_arb *n);
t_nod_arb *tree_search(t_nod_arb *n, int key);
t_nod_arb *iterative_tree_search(t_nod_arb *n, int key);
void tree_insert(t_arbore *arbore, t_nod_arb *n);
void transplant(t_arbore *arbore, t_nod_arb *u, t_nod_arb *v);
void tree_delete(t_arbore *arbore, t_nod_arb *n);

#endif // ARBORE_H_INCLUDED
