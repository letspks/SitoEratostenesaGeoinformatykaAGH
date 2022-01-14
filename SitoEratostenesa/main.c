#include <stdio.h>
#include <stdlib.h>


int main()
{
    int n;
    int i;
    int j;
    int q;

    printf("Algorytm wypisujacy liczby pierwsze mniejsze od N metoda sita Eratostenesa\n");
    FILE *plik = fopen("nte.txt", "r");
    printf("Plik powinien zawierac 10 zmiennych\n");
    if(plik==NULL)
    {
        perror("NIE MOZNA ZLOKALIZOWAC PLIKU NTE\n");
        exit(0);
    }
    printf("Plik otwarty pomyslnie\n");
    int tabx[10];


    for(int k=0; k<10; k=k+1)
    {
        n=tabx[k];
        printf("Obliczanie dla liczby:");
        printf("%d", n);

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
}
