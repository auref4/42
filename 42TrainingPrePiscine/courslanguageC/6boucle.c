#include <stdio.h>

int main()
{

    int i = 0;
    int i2 = 10;
    int i3;
    int i4 = 0;
    

    while (i < 10) // creer une boucle (tant que)
    {
        printf("i vaut %d\n", i);
       i++;
    }
    do // do while permet de rentrer dans le code une fois même si la condition n'est pas respecté
    {
        printf("i2 vaut %d\n", i2);
        i2++;
    }
    while (i2 < 10); // point virgule obligatoire a la fin pour do while
    
    for (i3 = 0; i3 < 10; i3++) // permet de creer une boucle sans perdre de temps, initialisation + affectation directement au niveau de la boucle 'for'
        printf("i3 vaut %d\n", i3);
    
    for (; i4 < 10; i4++) // alternative au cas precedent
        {   
        printf("i4 vaut %d\n", i4);
        printf("autre chose\n");
        }

    
    
    printf("Boucle terminée !\n");



    return 0;
}