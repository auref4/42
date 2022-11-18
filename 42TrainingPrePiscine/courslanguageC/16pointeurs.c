
// Pointeurs et Tableaux, les tableaux se comporte comme des pointeurs

#include <stdio.h>

// void remplirTableau(int tab[0], int size)
void remplirTableau(int * tab, int size)
{
    int i;
    for (i = 0; i < size; i++)
        *(tab + i) = 100 * i; // tab[i] = 100 * i;
}

int main()
{
    int tabEntier[5];
    int taille = 5;
    int i;

    tabEntier[0] = 15;
    tabEntier[1] = 25;

    // printf("valeur de tabEntier[0] = %d\n", tabEntier[0]);
    printf("valeur de tabEntier[0] = %d\n", *(tabEntier + 1));

    // tabEntier <=> &tabEntier[0] écrire chaine est équivalent à écrire l'adresse de chaine 0
    // chaine <=> &chaine[0] écrire chaine est équivalent à écrire l'adresse de chaine 0
    // Tab[i] <=> *(tab + i)

    for (i = 0; i < taille; i++)
        printf ("tabEntier [%d] = %d\n", i, tabEntier[i]);

    remplirTableau(tabEntier, taille);
    printf("\n===========\n");
    
    for (i = 0; i < taille; i++)
        printf ("tabEntier [%d] = %d\n", i, tabEntier[i]);

    // printf("%p\n", chaine);
    // printf("%p\n", &chaine[0]);
   
    /*
    printf("Quel est votre prénom ?\n");
    scanf("%s", chaine);

    printf("Quel âge avez-vous ?\n");
    scanf("%d", &a); //quand on demande un entier dans scanf on demande une adresse &a

    printf("Prénom => %s | age => %d\n", chaine, a);
    */
    
    
    return 0;
}