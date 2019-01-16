#include <stdio.h>
#include <stdlib.h>
#include "arbore.h"

void make_root(t_arbore *arbore, int key)
{
    arbore->root=(t_nod_arb*)malloc(sizeof(t_nod_arb));
    arbore->root->key=key;
    arbore->root->left=NULL;
    arbore->root->right=NULL;
    arbore->root->parent=NULL;
}

t_nod_arb *create_node(int key)
{
    t_nod_arb *n=(t_nod_arb*)malloc(sizeof(t_nod_arb));
    n->key=key;
    n->left=NULL;
    n->right=NULL;
    n->parent=NULL;
    return n;
}

void preorder_walk(t_nod_arb *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->key);
        preorder_walk(root->left);
        preorder_walk(root->right);
    }
}

void postorder_walk(t_nod_arb *root)
{
    if(root!=NULL)
    {
        postorder_walk(root->left);
        postorder_walk(root->right);
        printf("%d ",root->key);
    }
}

void inorder_walk(t_nod_arb *root)
{
    if(root!=NULL)
    {
        inorder_walk(root->left);
        printf("%d ",root->key);
        inorder_walk(root->right);
    }
}

t_nod_arb *tree_min(t_nod_arb *n)
{
    while(n->left!=NULL)
        n=n->left;
    return n;
}

t_nod_arb *tree_max(t_nod_arb *n)
{
    while(n->right!=NULL)
        n=n->right;
    return n;
}

t_nod_arb *tree_successor(t_nod_arb *n)
{
    t_nod_arb *x;
    t_nod_arb *y;
    if(n->right!=NULL)
        return tree_min(n->right);
    y=n->parent;
    while((y!=NULL)&&(n==y->right))
    {
        n=y;
        y=y->parent;
    }
    return y;
}

t_nod_arb *tree_search(t_nod_arb *n, int key)
{
    if((n==NULL)||(key==n->key))
        return n;
    if(key<n->key)
        return tree_search(n->left,key);
    else
        return tree_search(n->right,key);
}

t_nod_arb *iterative_tree_search(t_nod_arb *n, int key)
{
    while((n!=NULL)&&(key!=n->key))
        if(key<n->key)
            n=n->left;
        else
            n=n->right;
    return n;
}

void tree_insert(t_arbore *arbore, t_nod_arb *n)
{
    t_nod_arb *x;
    t_nod_arb *y;
    y=NULL;
    x=arbore->root;
    while(x!=NULL)
    {
        y=x;
        if(n->key<x->key)
            x=x->left;
        else
            x=x->right;
    }
    n->parent=y;
    if(y==NULL)
        arbore->root=n;
    else
    {if(n->key<y->key)
        y->left=n;
    else
        y->right=n;}
}

void transplant(t_arbore *arbore, t_nod_arb *u, t_nod_arb *v)
{
    if(u->parent==NULL)
        arbore->root=v;
    else
    {
        if(u==u->parent->left)
            u->parent->left=v;
        else
            u->parent->right=v;
    }
    if(v!=NULL)
        v->parent=u->parent;
}

void tree_delete(t_arbore *arbore, t_nod_arb *n)
{
    t_nod_arb *y;
    if(n->left==NULL)
        transplant(&arbore,n,n->right);
    else
    {
        if(n->right==NULL)
            transplant(&arbore,n,n->right);
        else
        {
            y=tree_min(n->right);
            if(y->parent!=n)
            {
                transplant(&arbore,y,y->right);
                y->right=n->right;
                y->right->parent=y;
            }
            transplant(&arbore,n,y);
            y->left=n->left;
            y->left->parent=y;
        }
    }
}
