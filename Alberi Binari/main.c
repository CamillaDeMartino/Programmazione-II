#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main()
{
    /** Scrivere le function C per la visita (preorder, inorder e postorder) di un albero binario rappresentato
        mediante array. **/


    int albero[] = {-1, 0, 1, 2, 3, 4, 5, 6, -1, -1, 9, 10, 11, 12, 13, -1};
    int i = 1; //Da quale nodo comincio

    printf("           %hd\n",albero[1]);
    puts("         /   \\");
    puts("        /     \\");
    puts("       /       \\");
    puts("      /         \\");
    printf("     %hd           %hd   \n",albero[2],albero[3]);
    puts("    / \\         / \\"); puts("   /   \\       /   \\");
    printf("  %hd     %hd     %hd     %hd \n",albero[4],albero[5],albero[6],albero[7]);
    puts("       / \\   / \\   / ");
    printf("      %hd  %hd %hd %hd %hd \n",albero[10],albero[11],albero[12],albero[13],albero[14]);

    puts("\nVisita PREORDER");
    visita_preorder(albero,i);
    printf("\n");

    puts("\nVisita INORDER");
    visita_inorder(albero,i);
    printf("\n");

    puts("\nVisita POSTORDER");
    visita_postorder(albero,i);
    printf("\n");

    return 0;
}
