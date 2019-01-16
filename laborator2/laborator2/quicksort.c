/**#include <stdio.h>
#include <stdlib.h>
#include "array_io.h"

int partition(int a[], int p, int r)
{
    int x=a[r];
    int i=p-1;
    int j;
    for(j=p;j<r;j++)
        if(a[j]<=x)
        {
            i++;
            int aux=a[i];
            a[i]=a[j];
            a[j]=aux;
        }
    a[r]=a[i+1];**
    a[i+1]=x;
    return i+1;
}

void quick_sort(int a[], int p, int r)
{
    int q=0;
    if(p<r)
    {
        q=partition(a,p,r);
        quick_sort(a,p,q-1);
        quick_sort(a,q+1,r);
    }
}

void main(void)
{
    int a[100], n;
    printf("Introduceti numarul de elemente din sir: "); scanf("%d", &n);
    read_array(a,n);
    quick_sort(a,0,n-1);
    printf("Sirul sortat: ");
    print_array(a,n);
}
**/
