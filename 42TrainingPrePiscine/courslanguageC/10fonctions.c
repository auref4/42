#include <stdio.h>

/*
type_de_retour nom(parametre1, parametre2, ....)
{
    corps_de_la_fonction
    return valeur_de_retour;
}
*/

void afficherBonjour() // void veut dire vide, pas besoin de return car void ne renvoie rien
{
    printf("Bonjour!\n");
}

int carre(int n) 
{
    return n * n;
}

int maximum(int a, int b)
{
    int max;
    if (a > b)
        max = a;
    else  
        max = b; 

    return max;
}

int main ()
{
    int a;
    int b;

    afficherBonjour();
    // printf("Nombre dont vous souhaitez calculer le carré\n");
    printf("Premiere valeur : ");
    scanf("%d", &a);

    printf("Deuxieme valeur : ");
    scanf("%d", &b);

    printf("Maximum entre %d et %d : %d\n", a, b, maximum(a, b));
    
    // printf("%d * %d = %d\n", a, a, carre(a));

/*int main()
{
    afficherBonjour();
    afficherBonjour();
    afficherBonjour();
    afficherBonjour();
    afficherBonjour();
*/   
    
    return 0;
}