#ifndef STIVA_H_INCLUDED
#define STIVA_H_INCLUDED

typedef struct stiva{
    int top;
    int* data;
}t_stiva;


void init_stack(t_stiva *stiva, int init_size);
void free_stack(t_stiva *stiva);
int stack_empty(t_stiva stiva);
void print_stack(t_stiva stiva);
void pop(t_stiva *stiva);
void push(t_stiva *stiva, int k);
#endif // STIVA_H_INCLUDED
