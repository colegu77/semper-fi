#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "array_io.h"

int maxim(int a, int b)
{
    if(a<b)
        return b;
    else
        return a;
}

int read_prices(int a[], int n)
{
    int i;
    for(i=1; i<=n; i++)
    {
        printf("a[%d]=",i);
        scanf("%d", &a[i]);
    }
}

int memoized_cut_rod_aux(int p[], int n, int r[])
{
    int q;
    if(r[n]>0)
        return r[n];
    if(n==0)
        q=0;
    else
        q=INT_MIN;
    int i;
    for(i=1; i<=n; i++)
        q=maxim(q,p[i]+memoized_cut_rod_aux(p,n-i,r));
    r[n]=q;
    return q;
}

int memoized_cut_rod(int p[], int n)
{
    int r[30], i,q;
    for(i=0; i<=n; i++)
        r[i]=INT_MIN;
    q=memoized_cut_rod_aux(p,n,r);
    print_array(r,n);
    return q;
}

int cut_rod(int p[], int n)
{
    if(n==0)
        return 0;
    int q;
    q=INT_MIN;
    int i;
    for(i=1; i<=n; i++)
        q=maxim(q, p[i]+cut_rod(p,n-i));
    return q;
}

int bottom_up_cut_rod(int p[], int n)
{
    int r[30],j,i,q;
    r[0]=0;
    for(j=1; j<=n; j++)
    {
        q=INT_MIN;
        for(i=1; i<=j; i++)
            q=maxim(q,p[i]+r[j-i]);
        r[j]=q;
    }
    return r[n];
}
int main()
{
    int n, a[30],maxvalue;
    printf("Introduceti lungimea barei: ");
    scanf("%d",&n);
    read_prices(a,n);
    maxvalue=cut_rod(a,n);
    printf("%d \n",maxvalue);
    maxvalue=memoized_cut_rod(a,n);
    printf("%d \n",maxvalue);
    maxvalue=bottom_up_cut_rod(a,n);
    printf("%d",maxvalue);
    return 0;
}
