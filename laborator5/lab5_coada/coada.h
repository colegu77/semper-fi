#ifndef COADA_H_INCLUDED
#define COADA_H_INCLUDED

typedef struct coada{
    int tail;
    int head;
    int length;
    int *data;
}t_coada;

void init_queue(t_coada *coada, int init_size);
void free_queue(t_coada *coada);
int queue_empty(t_coada coada);
void enqueue(t_coada *coada, int element);
int dequeue(t_coada *coada);
void print_queue(t_coada coada);


#endif // COADA_H_INCLUDED
