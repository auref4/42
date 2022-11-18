#include <stdio.h>
// #define True 1
// #define False 0

// typedef type nouveau_type;    Permet de remplacer une variable par une variable personnalisée
typedef int entier;     
typedef enum { False, True } bool; // enum permet de faire une enumération ou les valeurs sont égal à { 0, 1, etc.. }, remplace la 2éme et 3éme ligne

int main ()
{
    entier a = 10;
    printf("a vaut %d\n", a);

    bool monBooleen = True; // int monBooleen = 0
    if (monBooleen) // 0
        printf("Salut !\n");

    return 0;
}