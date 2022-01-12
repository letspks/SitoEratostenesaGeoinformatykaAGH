#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n;
    int i;
    int j;
    int q;

    printf("Algorytm wypisujacy liczby pierwsze mniejsze od N metoda sita Eratostenesa\n");
    printf("Podaj N:\n");
    scanf("%d", &n);
    printf("Podales liczbe:\n");
    printf("%d", n);
    printf("\n");
    int liczby[n];
    int liczbygotowe[n];
    for(int i=0; i<n; i=i+1)
    {
        liczby[i]=1+i;
        liczbygotowe[i]=1+i;
    }
    printf("\n");
    for(int i=1; liczbygotowe[i]*liczbygotowe[i]<=n; i=i+1)
    {
        for(int q=2; liczbygotowe[i]*q<=n; q=q+1)
        {
            liczby[(liczby[i]*q)-1]=0;
        }
    }
    printf("Liczby pierwsze mniejsze od podanego N to:\n");
    for(int i=0; i<n; i=i+1)
    {
        if(liczby[i]!=0)
        {
            printf("%d", liczbygotowe[i]);
            printf("\n");
        }

    }
}
