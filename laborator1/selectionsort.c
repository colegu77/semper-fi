#include <stdio.h>
#include <stdlib.h>
#include "array_io.h"

void selection_sort(int a[], int n)
{
    int i,j,aux;
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
            if(a[j]<a[i])
            {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
}

int main()
{
    int a[20], n;
    printf("Introduceti nr de elemente: "); scanf("%d", &n);
    read_array(a,n);
    selection_sort(a,n);
    print_array(a,n);
    return 1;
}

