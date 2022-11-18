#include <stdio.h>
#include <string.h>

// struct nom {Parametres variables}
// struct Livre
/*struct Livre 
{
    char titre [100];
    char auteur [100];
    int annee;
};*/

    
// Pas oublier ; à la fin d'une structure

typedef struct  // Possibilité de créer structure anonyme et de directement la désigner dans le typedef
{
    char titre [100];
    char auteur [100];
    int annee;
} Livre;

void afficherLivre(Livre livre)
{
    printf("============\n");
    printf("Titre : %s\n", livre.titre);
    printf("Auteur : %s\n", livre.auteur);
    printf("Année : %d\n", livre.annee);
    printf("============\n");
}

int main()
{
    //Livre livre1;
    //Livre livre2;
    Livre bibliotheque[100];
    int nbLivres = 0;
    int i;

    bibliotheque[0].annee = 1997;
    strcpy(bibliotheque[0].titre, "Harry Potter"); // strcpy permet de copier une chaine de caractere dans une varialbe
    strcpy(bibliotheque[0].auteur, "JK Rowling");
    nbLivres++;
    
    // livre1.titre = "Harry Potter";
    //strcpy(livre1.titre, "Harry Potter");
    //strcpy(livre1.auteur, "JK Rowling");
    
    bibliotheque[1].annee = 1943;
    strcpy(bibliotheque[1].titre, "Le petit prince");
    strcpy(bibliotheque[1].auteur, "Antoine de Saint-Exupéry");
    nbLivres++;

    //livre2.annee = 1943;
    //strcpy(livre2.titre, "Le petit prince");
    //strcpy(livre2.auteur, "Antoine de Saint-Exupéry");

    //afficherLivre(livre1);
    //afficherLivre(livre2);

    for (i = 0; i < nbLivres; i++)
        afficherLivre(bibliotheque[i]);

    return 0;
}