#include <stdio.h>
#include <stdlib.h>
#include "array_io.h"

int heap_size;

int left(int x)
{
    return 2*x+1;
}

int right(int x)
{
    return 2*x+2;
}

void max_heapify(int a[], int x)
{
    int l=left(x);
    int r=right(x);
    int largest, aux;
    if((l<=heap_size)&&a[l]>a[x])
        largest=l;
    else
        largest=x;
    if((r<=heap_size)&&a[r]>a[largest])
        largest=r;
    if(largest!=x)
    {
        aux=a[x];
        a[x]=a[largest];
        a[largest]=aux;
        max_heapify(a, largest);
    }

}
void build_max_heap(int a[], int n)
{
    heap_size=n-1;
    int i;
    for(i=n/2-1;i>=0;i--)
        max_heapify(a,i);

}

void heap_sort(int a[], int n)
{
    build_max_heap(a,n);
    int i, aux;
    for(i=n-1;i>0;i--)
    {
        aux=a[0];
        a[0]=a[i];
        a[i]=aux;
        heap_size--;
        max_heapify(a,0);
    }
}

void main(void)
{
    int a[100], n;
    printf("Introduceti numarul de elemente din sir: "); scanf("%d", &n);
    read_array(a,n);
    heap_sort(a,n);
    printf("Sirul sortat este: ");
    print_array(a,n);
}
