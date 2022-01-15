#include <stdio.h>                                                                           //implementacja podstawowych bibliotek
#include <stdlib.h>


int main()
{
    int n;                                                                                   //deklarowanie typow zmiennych
    int i;
    int j;
    int q;

    printf("Algorytm wypisujacy liczby pierwsze mniejsze od N metoda sita Eratostenesa\n");  //wypisywanie inforamcji zwrotnych do uzytkownika
    FILE *plik = fopen("nte.txt", "r");                                                      //otwarcie wskazanego pliku
    printf("Plik powinien zawierac 10 zmiennych\n");
    if(plik==NULL)                                                                           //sprawdzenie czy plik zostal pomyslnie znaleziony
    {
        perror("NIE MOZNA ZLOKALIZOWAC PLIKU NTE\n");                                        //informacja zwrotna o braku pliku
        exit(0);                                                                             //stopowanie petli i jednoczesnie zakonczenie programu
    }
    printf("Plik otwarty pomyslnie\n");                                                      //informacja zwrotna o znalezieniu pliku
    int tabx[10];                                                                            //utworzenie tablicy pomoczniczej tabx, do której zapisane zostana liczby z pliku
    int x=0;                                                                                 // ustawienie indeksu x na 0

   while(feof(plik) == 0)
   {
      fscanf(plik,"%d",&tabx[x]);                                                           //pobieranie danych z pliku do tabeli tabx
      x=x+1;
   }
    for(int k=0; k<10; k=k+1)                                                               //wejscie do petli wykonujacej obliczenia dla kazdego N z osobna
    {
        n=tabx[k];                                                                          //pobieranie liczby n z odpowiedniego pola tabx[k]
        printf("Obliczanie dla liczby: ");                                                  //informacja jaka liczbe pobrano
        printf("%d", n);
        printf("\n");
        int liczby[n];                                                                      //utworzenie tablicy liczby[n]
        int liczbygotowe[n];                                                                //utworzenie tablicy pomocniczej liczbygotowe[n]

        for(int i=0; i<n; i=i+1)                                                            //petla wypelniajaca obie tablice liczbami od 1 do n
        {
            liczby[i]=1+i;
            liczbygotowe[i]=1+i;
        }
        printf("\n");
        for(int i=1; liczbygotowe[i]*liczbygotowe[i]<=n; i=i+1)                             //ustawienie wskaznika i=1, sprawdzanie warunku czy wartosc kryjaca sie pod i
        {                                                                                   //na tablicy pomocniczej jest mniejsza badz rowna od pierwiastka z n
            for(int q=2; liczbygotowe[i]*q<=n; q=q+1)                                       //ustawienie mnoznika q=2, sprawdzenie czy mnoznik*liczba pod i nie przeskoczy n
            {
                liczby[(liczby[i]*q)-1]=0;                                                  //usuwanie wielokrotnosci liczby 1 z tablicy glownej (zamiana ich na 0)
            }
        }
        liczby[0]=0;                                                                        //usuniecie z tablicy glownej liczby 1 (zamiana na 0)
        printf("Liczby pierwsze mniejsze od podanego N to:\n");                             //informacja zwrotna po przesianiu
        printf("\n");
        for(int i=0; i<n; i=i+1)                                                            //ustawienie wskaznika i=0, sprawdzanie czy nie przeskoczy n po inkrementacji
        {
            if(liczby[i]!=0)                                                                //sprawdzenie czy w tablicy glownej pod i'tym indeksem znajduje sie liczba inna od 0
            {                                                                               //doslownie jest to sprawdzenie czy liczba nie zostala odsiana przez sito
                printf("%d", liczbygotowe[i]);                                              //wypisanie konkretnej liczby pod i'tym indeksem jako liczby pierwszej
                printf("\n");
            }

        }
        printf("\n");
    }
}
