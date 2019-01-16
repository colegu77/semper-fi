#ifndef ARBORE_RB_H_INCLUDED
#define ARBORE_RB_H_INCLUDED

typedef struct rb_node{
    enum { red, black } color;
    int key;
    struct rb_node *left, *right, *parent;
}t_rb_node;

typedef struct {
    t_rb_node *root;
}t_rb_arbore;

void make_root(t_rb_arbore *arbore, int key);
t_rb_node *create_node(int key);
void inorder_walk(t_rb_node *root);
t_rb_node *tree_search(t_rb_node *n, int key);
void left_rotate(t_rb_arbore *t, t_rb_node *x);
void right_rotate(t_rb_arbore *t, t_rb_node *y);
void rb_insert_fixup(t_rb_arbore *t, t_rb_node *z);
void rb_insert(t_rb_arbore *t, t_rb_node *z);

#endif // ARBORE_RB_H_INCLUDED
