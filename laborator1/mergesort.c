/**#include <stdio.h>
#include <stdlib.h>
#include "array_io.h"
#include <limits.h>

void merge(int a[],int p,int q,int r)
{
    int i, j, k;
    int left[100],right[100];
    int n1=q-p+1;
    int n2=r-q;
    for(i=0; i<=n1; i++)
        left[i]=a[p+i-1];
    for(j=0; j<=n2; j++)
        right[j]=a[q+j];
    left[n1+1]=INT_MAX;
    right[n2+1]=INT_MAX;
    i=1;
    j=1;
    for(k=p; k<=r; k++)
        if(left[i]<=right[j])
        {
            a[k]=left[i];
            i++;
        }
        else
        {
            a[k]=right[j];
            j++;
        }

}

void merge_sort(int a[], int p, int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        merge_sort(a,p,q);
        merge_sort(a, q+1, r);
        merge(a,p,q,r);
    }
}

void main(void)
{
    int n, a[100];
    printf("Introduceti lungimea sirului: "); scanf("%d", &n);
    read_array(a,n);
    merge_sort(a,0,n-1);
    printf("\n\n\n");
    print_array(a,n);
}

**/
