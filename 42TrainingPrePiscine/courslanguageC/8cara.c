#include <stdlib.h>
#include <stdio.h>

int main() {
    
    //char chaine[6] = {'H', 'e', 'l', 'l', 'o', '\0'}; // \0 caractere qui permet de mettre fin a une suite de caractere (doit rajouter une case au tableau pour ce caractere)
    //int i;
    
    char chaine [50] = "Hello"; // Moyen plus simple d'affecter des lettres au cases, ne pas oublier les ""
    
    chaine[0] = 'H';
    chaine[1] = 'i';
    chaine[2] = '!';
    chaine[3] = '\0';
    
    //for 
        //(i = 0; i < 6; i++)
        //printf("%c", chaine[i]);
    
    printf("%s", chaine); // %s veut dire string, permet d'afficher une suite de caractere beaucoup plus facilement

    printf("\n");   


    return 0;
}