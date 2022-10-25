#include <stdio.h>

int main() {

    int a = 10;
    int b = 10;
    int c = 9;
    int res;
    int res2;
    int res3;
    int res4;
    int res5;
    int res6;
    float res7 = 0.2 * 0.3;

    res = a == b; // operateur comparaison (= affectation, == sont-elle egale?, != sont-elle differente?, < inferieure?, > supérieure?, >= superieure ou egale?, etc)
    res2 = (a + 1 != b); // opérations arithmetique toujours prioritaire aux operateurs de comparaison
    res3 = (a == b && b == c); // opérateurs logique (&& (et) calculer plusieurs comparaisons (égales et égales, égales et inférieures etc..))
    res4 = (a == b || b == c); // || (ou) une comparaison est vraie ? ou l'autre ? ou les deux (inclusif et non pas exclusif)                                           
    res5 = !(a == b || b == c); // ! inverse un résultat de comparaison
    res6 = res && res2; // possibilite d'utiliser operateur de comparaison entre variable

    
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("res = %d\n", res);
    printf("res2 = %d\n", res2);
    printf("res3 = %d\n", res3);
    printf("res4 = %d\n", res4);
    printf("res5 = %d\n", res5);
    printf("res6 = %d\n", res6);
    printf("res7 = %.15f\n", res7); // permet d'afficher plus de precision (15 decimales apres la virgule) pas toujours juste car nombre flottant est aproximatif
    


    return 0;
}