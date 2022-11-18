// L'allocation de mémoire dynamique (malloc)

#include <stdio.h>
#include <stdlib.h> // permet d'ajouter malloc grave a la library standard

int main()
{
    // int a = 10;
   /* int * pa = malloc(sizeof(int)); // memory allocation, sizeof permet de decider de la taille donnée sizeof(int)
    if (pa == NULL)
    {
        printf("Erreur malloc !\n");
        return 1;
    }

    *pa = 10;

    printf("Adresse de pa : %p\n", pa);
    printf(" Valeur à l'adresse pointée par pa : %d\n", *pa);
    
    free(pa); // permet de liberer la mémoire, il doit y avoir un free a chaque maloc */
    
    
    //int tab [5];
    int * tab = malloc(5 * sizeof(int)); // permet de donner 5 fois la taille d'un entier (tab[5])

    tab [0] = 0;
    tab [1] = 10;
    tab [2] = 20;
    tab [3] = 30;
    tab [4] = 44;

    int i = 0;
    for (i = 0; i < 5; i++)
        printf("tab[%d] = %d\n", i, tab[i]);
    
    free(tab);
    
    return 0;
}