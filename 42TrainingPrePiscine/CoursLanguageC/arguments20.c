// Utiliser des arguments dans ses programmes

#include <stdio.h>

// argc = argument count = nombre d'arguments
// argv = arguments values = valeurs des arguments
// char ** = tableau de chaînes de caractères, char **argv peut s'écrire char **argv
int main(int argc, char *argv[])   
{
    /* int i;

    printf("Nombre d'arguments : %d\n", argc);
    
    for (i = 0; i < argc; i++)
    {
        printf("Arguments %d : %s\n", i, argv[i]); // le premier argument argv[0] est toujours le nom de notre programme
    } */
    
    if (argc != 2)
    {
        printf("Utilisation du programme : %s <prenom>\n", argv[0]);
        return 1;
    }

    printf("Bonjour %s :)\n", argv[1]);


    return 0;
}