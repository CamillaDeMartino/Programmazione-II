#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Data;

struct linked_list{

    Data d;
    struct linked_list *next;

};


typedef struct linked_list ELEMENT;
typedef ELEMENT *Link;

Link array_to_list(Data []);
int main()
{
    /** A partire dalla versione ricorsiva di una lista in C, scrivere la versione iterativa. **/

    Data c_arr[] = "Questa e' una stringa di prova!";
    Link head_list, p_list;

    head_list = array_to_list(c_arr);

    p_list = head_list;

    while(p_list != NULL)
    {
        putchar(p_list -> d);
        p_list = p_list->next;
    }

    printf("");
    return 0;
}


Link array_to_list(Data s[])
{
    Link head, nodo;
    int len;

    head = NULL;
    len = strlen(s);

    while(len > 0)
    {
        nodo = (ELEMENT *)calloc(1, sizeof(ELEMENT));
        nodo ->d = s[len-1];
        nodo -> next =  head;

        head = nodo;
        len--;
    }
    return head;
}
