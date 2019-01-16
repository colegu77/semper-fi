/**include <stdio.h>
#include <stdlib.h>

int nr_sol;

void tipareste_solutie(int x[], int n)
{
    printf("\n");
    printf("Solutia numarul %d este: ", nr_sol);
    printf("\n");

    int i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(x[i]==j)printf("R ");
            else printf(". ");
        }
        printf("\n");
    }
}


int se_ataca(int x[], int pos)
{
    int i;
    for(i=1; i<=pos-1; i++)
    {
        if((x[i]==x[pos] || (abs(x[i]-x[pos])==abs(i-pos)) ))return 1;
    }

    return 0;
}

void dame(int x[], int n, int k)
{
    if(k>n)
    {
        nr_sol++;
        tipareste_solutie(x,n);
    }
    else
    {
        x[k]=1;
        while(x[k]<=n)
        {
            if(!se_ataca(x,k))
                dame(x,n,k+1);

            x[k]++;
        }

    }
}


void main(void)
{
    nr_sol=0;
    int x[10],n;

    printf("Numarul de dame:");
    scanf("%d", &n);

    dame(x,n,1);

    printf("Numarul de solutii este:%d", nr_sol);

}**/
