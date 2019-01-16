#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//PROBLEMA DAMELOR

int nr_sol;

int seataca(int x[], int pos)
{
    int i;
    for(i=1; i<pos; i++)
        if((x[i]==x[pos]) || (abs(x[i]-x[pos])==abs(i-pos)))
            return 1;
    return 0;
}

void tipareste_solutie(int x[], int n)
{
    int i,j;
    printf("\n");
    printf("Solutia cu numarul %d este:\n", nr_sol);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(x[i]==j)
                printf("%c ",176);///dama

            else
                printf("%c ",178);///liber

        }
        printf("\n\n");
    }
}
void dame(int x[], int n)
{
    int i, k=1;
    for(i=1; i<=n; i++)
        x[i]=0;
    while(k>0)
    {
        if(k>n)
        {
            nr_sol++;
            tipareste_solutie(x,n);
            k--;
        }
        else
        {
            x[k]=x[k]+1;
            if(x[k]<=n)
            {
                if(!seataca(x,k))
                {
                    k++;
                }
            }
            else
            {
                x[k]=0;
                k--;
            }
        }
    }
}
void main(void)
{
    nr_sol=0;
    int x[200],n;
    printf("Introduceti numarul de dame: ");
    scanf("%d", &n);
    dame(x,n);
    printf("\n\nNumarul gasit de solutii este %d", nr_sol);
}

