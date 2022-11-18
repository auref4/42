#include <stdio.h>

#define MAX_BUFFER_SIZE 1000

int main()
{
     FILE * fp; // FILE pour créer un fichier * pour qu'il soit pointé

    fp = fopen("fichier18.txt", "r"); // fopen pour l'ouvrir("NOMDUFICHIER.x", "r" pour lire un fichier text, se réferer a fopen dans le man)
    if (fp == NULL)
    {
        printf("Erreur fopen\n");
        return 1;
    }

    /*char c = fgetc(fp);
    while (c != EOF) // End of file, le programme lire tant que c'est pas la fin du fichier(int)           
    {                                                                                                   
        printf("%c", c);                                                                                
        c = fgetc(fp); // fgetc (file get char) permet de lire un caractere dans un fichier (NOMDUFICHIER.x)              // METHODE CARACTERE/CARACTERE
    }                                                                                                  
    char c;                                                                                                     
    while((c = fgetc(fp)) != EOF)                                                                       
        printf("%c", c);                                                                                                                            */                                                                          
    
    
    
    
    

    // char str[1000];
    char str[MAX_BUFFER_SIZE];                                                                                           // METHODE LIGNE/LIGNE
    while (fgets(str, MAX_BUFFER_SIZE, fp) != NULL) // fgets(file fet string) permet de lire une chaine de caractere dans un fichier, 
        printf("%s", str);                          // NULL, le programme lire tant que c'est pas la fin du fichier(pointeur*)

    fclose(fp); // Fermer la mémoire donneé a un fichier

    return 0;
}