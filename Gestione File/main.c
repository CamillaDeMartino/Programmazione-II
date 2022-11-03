#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 30
int main()
{
    //scrittura file di caratteri
    /*
    char *testo = "Nel mezzo del cammin di nostra vita\n";
    char *cp, nome_file[13];
    FILE *fp;

    printf("Inserisci nome file: ");
    fgets(nome_file,9,stdin);

    nome_file[strlen(nome_file)-1]='\0';

    strcat(nome_file, ".txt");

    fp = fopen(nome_file,"w");
    cp = testo;

    while(*cp != '\0')
    {
        putc(*cp,fp);
        cp++;
    }

    fclose(fp);

    */

    //lettura bufferizzata

    char buffer[BUFSIZE], nomefile[20];
    FILE *fp;

    puts("Inserire il nome del file:");
    fgets(nomefile,20,stdin);
    nomefile[strlen(nomefile)-1]='\0';

    strcat(nomefile, ".txt");

    fp = fopen(nomefile,"r");
    if(fp == NULL)
        {
            puts("Errore apertura file");
            exit(1);
        }

    while( !feof(fp))
    {
        fgets(buffer,BUFSIZE,fp);
        printf("%s", buffer);
    }
    return 0;
}
