#include <stdio.h>

int main() {
 
    int nombre_entier;
    float nombre_decimal = 9.98;
    char caractere; // 1 octet (8 bits)


    nombre_entier = 42; // Affectation de 42 à nombre_entier
    caractere = 'a';

    printf("Bienvenue dans notre programme!\n");
    printf("Un entier => %d\n", nombre_entier);
    printf("Un decimal => %f\n", nombre_decimal);
    printf("Un caractere => %c\n", caractere);

    printf("Un caractere %c a la valeur %d selon ASCII\n",caractere, caractere);

    return 0;
}