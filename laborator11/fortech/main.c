#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int substrings(char A[20], char B[20])
{
    int i, j, k=0;
    char letter=A[0];
    for(i=0;i<strlen(B);i++)
        if(B[i]==letter)
            {j=i;
            break;}
    if(j<strlen(B))
        while(A[k]==B[j])
    {
        j++;
        k++;
    }
    else
        return 0;
    if((k==strlen(A)-1) && (j<strlen(B)))
        return 1;
}

int main()
{
    char a[20], b[20];
    printf("Introduceti primul sir: ");
    gets(a);
    printf("\nIntroduceti cel de-al doilea sir: ");
    gets(b);
    if(substrings(a,b))
        printf("\nPrimul sir este subsir al celui de-al doilea.");
    else
         printf("\nPrimul sir nu este subsir al celui de-al doilea.");
    return 0;
}
