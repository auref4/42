#include <stdio.h>

int main() {

    int a;
    int b;
    int c;
    int d;
    int e;
    float f;
    float g = 9;
    char h = 'a';

    a = 5; // 5 = 2 * 2 + 1
    b = 2;
    c = a / b;
    d = a % b; // modulo pour pouvoir decomposer 5
    e = 9;
    e += 2; // accumulation (e = e + 2 ou e + 2)
            // pour rajouter 1 ou soutraire 1 etc = e++, e--
    f = 9. / 2;
    g /= 2;

    
    printf("%d/%d = %d * %d + %d\n", a, b, b, c, d);

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("d = %d\n", d);
    printf("e = %d\n", e);

    printf("f = %f\n", f);
    printf("g = %f\n", g);
    printf("h = %c (%d)\n", h, h); // possibilité calculer caractere entre eux grace a la table ASCII (exemple a++ = 98)
    
    
    return 0;

}