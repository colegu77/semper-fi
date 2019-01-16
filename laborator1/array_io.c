#include <stdio.h>
#include <stdlib.h>

void read_array(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("a[%d]= ", i);
        scanf("%d", &a[i]);
    }
}

void print_array(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("a[%d]= %d\n",i,a[i]);
}
