/**#include <stdio.h>
#include <stdlib.h>
#include "array_io.h"

void insertion_sort(int a[], int n)
{
    int i,j, key;
    for(j=0; j<n; j++)
    {
        key=a[j];
        i=j-1;
        while((i>=0)&&(a[i]>key))
        {
            a[i+1]=a[i];
            i--;
        }
        a[i+1]=key;
    }
}

void main(void)
{
    int n, a[100];
    printf("Introduceti lungimea sirului: "); scanf("%d", &n);
    read_array(a,n);
    insertion_sort(a,n);
    print_array(a,n);
}
**/
