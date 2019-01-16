/**#include <stdio.h>
#include <stdlib.h>

int n;

void read_array(int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("a[%d]=", i);
        scanf("%d", &a[i]);
    }
}

void print_array(int a[], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("a[%d]=%d", i,a[i]);
    }

}

int recursive_activity_selector(int s[], int f[], int i, int j, int a[])
{
    int static na=0;
    int m;
    m=i+1;

    while((m<j)&&(s[m]<f[i]))
    {
        m++;
    }

    if(m<j)
    {
        a[na++]=m;
        recursive_activity_selector(s,f,m,j,a);
    }
    else
        return 0;

    return na;
}

int greedy_activity_selector(int s[], int f[], int a[],int n)
{
    int na=0;
    int k=0;
    int m,j;

    for(m=1; m<n; m++)
    {
        if(s[m]>=f[k])
        {
            a[na++]=m;
            k=m;
        }
    }
    return na;
}


void main()
{
    int sol_rec[100],sol_iter[100], s[100],f[100],length_sol_rec,length_sol_int;

    printf("Introduceti numarul de activitati:");
    scanf("%d", &n);
    read_array(s,n);
    read_array(f,n);

    length_sol_rec= recursive_activity_selector(s,f,0,n,sol_rec);
    printf("Solutie recursiva:\n");
    print_array(sol_rec, length_sol_rec);

    length_sol_int=greedy_activity_selector(s,f,sol_iter,n);
    printf("\nSolutie iterativa:\n");
    print_array(sol_iter, length_sol_int);
}
**/
