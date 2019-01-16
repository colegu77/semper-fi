#include <stdio.h>
#include <stdlib.h>
#include "arbore_rb.h"

void make_root(t_rb_arbore *arbore, int key)
{
    arbore->root=(t_rb_node*)malloc(sizeof(t_rb_node));
    arbore->root->key=key;
    arbore->root->left=NULL;
    arbore->root->right=NULL;
    arbore->root->parent=NULL;
    arbore->root->color=black;
}

t_rb_node *create_node(int key)
{
    t_rb_node *n=(t_rb_node*)malloc(sizeof(t_rb_node));
    n->key=key;
    n->left=NULL;
    n->right=NULL;
    n->parent=NULL;
    n->color=black;
    return n;
}

void inorder_walk(t_rb_node *root)
{
    if(root!=NULL)
    {
        inorder_walk(root->left);
        printf("%d", root->key);
        if(root->color==black)
            printf("[b]");
        else
            printf("[r]");
        inorder_walk(root->right);
    }
}

t_rb_node *tree_search(t_rb_node *n, int key)
{
    if((n==NULL) || (key==n->key))
        return n;
    if(key<n->key)
        return tree_search(n->left,key);
    else
        return tree_search(n->right,key);
}

void left_rotate(t_rb_arbore *t, t_rb_node *x)
{
    t_rb_node *y;
    y=x->right;
    x->right=y->left;
    if(y->left!=NULL)
        y->left->parent=x;
    y->parent=x->parent;
    if(x->parent==NULL)
        t->root=y;
    else{
        if(x==x->parent->left)
            x->parent->left=y;
        else
            x->parent->right=y;
    }
    y->left=x;
    x->parent=y;
}

void right_rotate(t_rb_arbore *t, t_rb_node *y)
{
    t_rb_node *x;
    x=y->left;
    y->left=x->right;
    if(x->right!=NULL)
        x->right->parent=y;
    x->parent=y->parent;
    if(y->parent==NULL)
        t->root=x;
    else{
        if(y==y->parent->right)
            y->parent->right=x;
        else
            y->parent->left=x;
    }
    x->right=y;
    y->parent=x;
}

void rb_insert_fixup(t_rb_arbore *t, t_rb_node *z)
{
    t_rb_node *y;
    while((z->parent!=NULL) && (z->parent->color==red))
    {
        if(z->parent==z->parent->parent->left)
        {
            y=z->parent->parent->right;
            if((y!=NULL) && (y->color==red))
            {
                z->parent->color=black;
                y->color=black;
                z->parent->parent->color=red;
                z=z->parent->parent;
            }
            else{
                if(z==z->parent->right)
            {
                z=z->parent;
                left_rotate(t,z);
            }
        z->parent->color=black;
        z->parent->parent->color=red;
        right_rotate(t,z->parent->parent);}
        }
        else
        {
            y=z->parent->parent->left;
            if((y!=NULL) && (y->color==red))
            {
                z->parent->color=black;
                y->color=black;
                z->parent->parent->color=red;
                z=z->parent->parent;
            }
            else{
                if(z==z->parent->left)
                {
                    z=z->parent;
                    right_rotate(t,z);
                }

            z->parent->color=black;
            z->parent->parent->color=red;
            left_rotate(t,z->parent->parent);}
        }
    }
    t->root->color=black;
}

void rb_insert(t_rb_arbore *t, t_rb_node *z)
{
    t_rb_node *y=NULL;
    t_rb_node *x=t->root;
    while(x!=NULL)
    {
        y=x;
        if(z->key<x->key)
            x=x->left;
        else
            x=x->right;
    }
    z->parent=y;
    if(y==NULL)
        t->root=z;
    else{
        if(z->key<y->key)
            y->left=z;
        else
            y->right=z;
    }
    z->left=NULL;
    z->right=NULL;
    z->color=red;
    rb_insert_fixup(t,z);
}
