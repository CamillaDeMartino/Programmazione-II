#include <stdio.h>
#include "Header.h"

void allocazione_statica(int n, char stringa[])
{
    int i, c;

    for(i = 0; i < n; i++)
    {
        c = getchar();
        stringa[i] = (char)c;

    }

    stringa[i] = '\0';
}

void allocazione_dinamica(int n, char **stringa)
{
    *stringa = (char*)malloc(n+1);
    int i, c;

    for(i = 0; i < n; i++)
    {
        c = getchar();
        *(*stringa+i) = (char)c;
    }
    *(*stringa+i) = '\0';
}


void concatenazione(int n, int m, char *stringa1, char *stringa2, char *conc)
{
    int i;

    for(i = 0; i < n; i++)
        *(conc + i) = *(stringa1 + i);
    for(int j = 0; j <= m; j++, i++)
        *(conc + i) = *(stringa2 + j);
}


int occorrenze (int n, int m, char stringa1[], char stringa2[])
{
    int i;

    for(i = 0; i < n-m+1; i++)
    {
        if (trova_parole(m, &stringa1[i], stringa2) != -1)
            return i;
    }
    return -1;
}


int trova_parole(int n, char testo[], char chiave[])
{
    int i;

    for(i = 0; i < n; i++)
    {   if(testo[i] != chiave[i])
            return -1;
    }

        return 1;
}


int occorrenze2(int n, int m, char stringa1[], char stringa2[], int array_pos[])
{
    int i, j = 0, occ = 0;

    for(i = 0; i < n-m+1; i++)
    {
        if (trova_parole(m,&stringa1[i], stringa2) != -1)
        {
            occ++;
            array_pos[j] = i;
            j++;
        }
    }
    return occ;
}
