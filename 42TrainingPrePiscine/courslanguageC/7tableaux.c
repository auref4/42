#include <stdio.h>

int main()
{
    // type nom [taille];

    int tab[44]; // 0, 1, 2 et non pas 1, 2, 3       [3] = {0} permet de mettre des 0 dans les cases
    int longueur = 44;
    int i;

    // int tab[N];
    // Indinces : 0 à N - 1
   
    // nom [clé/indice] = valeur;
    //tab[0] = 1;
    //tab[1] = 2;
    //tab[2] = 3;
    // tab[3] = 4; ERREUR car max 3 tableaux défini


    for (i = 0; i < longueur; i++)
        tab[i] = i + 1;


    for (i = 0; i < longueur; i++)
        printf("Mon nombre tab[%d] vaut %d\n", i, tab[i]);


    
    //printf("Mon nombre tab[0] vaut %d\n", tab[0]);
    //printf("Mon nombre tab[1] vaut %d\n", tab[1]);
    //printf("Mon nombre tab[2] vaut %d\n", tab[2]);









    return 0;
}