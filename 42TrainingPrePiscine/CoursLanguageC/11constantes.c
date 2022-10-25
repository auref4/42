#include <stdio.h>
/* #define NOM VALEUR      Créer des macros processeur */
#define TAILLE_TABLEAU 10
#define LONGUEUR_MAX_PRENOM 255

int main()
{
    
    /* const int A = 10;  /* Const veut dire constante */
    int tab[TAILLE_TABLEAU] = {1, 2, 3};
    char prenom [LONGUEUR_MAX_PRENOM] = "Antoine";
    int i;
    
    
    printf("Ma constante vaut %d\n", TAILLE_TABLEAU);

    printf("Nous sommes à la ligne %d\n", __LINE__);  /* __LINE__    Macro permettant de dire à quelle ligne de code nous sommes */
    printf("Nous sommes dans le fichier %s\n", __FILE__); /* __FILE__   Macro permettrant de dire dans quel fichier nous sommes */

    printf("%s \n", prenom);

    for (i = 0; i < TAILLE_TABLEAU; i++)
        printf("tab[%d] = %d\n", i, tab[i]);


    return 0;
}