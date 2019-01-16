/**#include <stdio.h>
#include <stdlib.h>
#include "array_io.h"
#include <limits.h>

int m[20][20],s[20][20];

int matrix_chain_order(int p[], int n)
{
    n--;
    int  i, t, j, k,q;
    for(i=1;i<=n;i++)
        m[i][i]=0;
    for(t=2;t<=n;t++)
    {
        for(i=1; i<=n-t+1;i++)
        {
            j=i+t-1;
            m[i][j]=INT_MAX;
            for(k=i;k<j;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
}

int print_optimal_parens(int i, int j)
{
    if(i==j)
        printf("A%d",i);
    else{
        printf("(");
        print_optimal_parens(i,s[i][j]);
        print_optimal_parens(s[i][j]+1,j);
        printf(")");
    }
}

void main(void)
{
    int n, a[20];
    printf("n= ");
    scanf("%d", &n);
    read_array(a,n);
    matrix_chain_order(a,n);
    for(int i =1;i<n;i++)
    {
        for (int j =1;j<n;j++)
            printf("%d ",m[i][j]);
        printf("\n");
    }
    for(int i =1;i<n;i++)
    {
        for (int j =1;j<n;j++)
            printf("%d ",s[i][j]);
        printf("\n");
    }
    print_optimal_parens(1,n-1);
}**/
