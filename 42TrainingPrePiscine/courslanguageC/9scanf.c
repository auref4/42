#include <stdio.h>

int main() {
    char prenom [50];
    int age;

    printf("Comment vous appelez-vous ?\n");
    scanf("%s", prenom); // scanf permet de demander quelque chose a l'utilisateur

    printf("Vous vous appelez %s\n", prenom);

    printf("Quel âge avez vous ?\n");
    scanf("%d", &age); // ajoutez & quand la variable ajouter n'est pas un tableau

    printf("vous avez %d ans\n", age);

    if (age >= 21)
        printf("Vous êtes majeur !\n");
    else if (age >= 18)
        printf("Vous êtes majeur! mais pas aux USA\n");
    else
        printf("Vous êtes mineur !\n");
        


    return 0;
}