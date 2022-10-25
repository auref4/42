#include <stdio.h>

int main()
{
    int a = 10;
    int * pa = &a; // * permet de creer un pointeur sur l'adresse de la variable choisi (&a en l'occurence)

    printf("a = %d (adresse : %p)\n", a, &a); // %p permet d'afficher l'adresse de la variable (&a pour afficher le int a), peux fonctione avec %c mais pas meme rendu
    printf("=> %p\n", pa); // permet d'afficher le pointeur de l'adresse de la variable int a

    a = 20;
    *pa = 30; // On peut modifier directement la valeur en utilisant *pa =
    
    printf("La valeur stocké a l'adresse %p est %d\n", pa, *pa); // *pa permet de connaitre la valeur de l'entier stocké a l'adresse de la variable

    return 0;
}