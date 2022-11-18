#include <stdio.h>

int main()
{
    FILE * fp = fopen("fichier19.txt", "wx"); // w permet d'écrire dans un fichier au début (remplace ce qui a de deja écrit), wx si fichier existe déja ne peux pas le recreer
    //FILE * fp = fopen("fichier19.txt", "a"); // a permet d'écrire dans un fichier a la fin (rajoute apres de ce qui est deja écrit)
    if (fp == NULL)
    {
        printf("ERREUR NULL\n");
        return 1;
    }
    
    // fputc('b', fp); // fputc permet de mettre un char dans un fichier

    /*if (fputs("ça va ?", fp) == EOF) // fputs permet de mettre un chaine de caractere (string) dans un fichier
    { 
        printf("ERREUR EOF !!!\n");
        return 1;
    } */

    char str[] = "Thomas";
    int age = 20;

    fprintf(fp, "Bonjour je m'appelle %s et j'ai %d ans !\n", str, age); // fprintf s'utilise comme printf mais pour ecrire dans un fichier, possibilité d'utiliser des variables etc)
    printf("Bonjour je m'appelle %s et j'ai %d ans !\n", str, age); // le printf sera visible dans le terminal mais pas dans le fichier

    fclose(fp); // fclose permet de fermer un fichier auparavent ouvert

    return 0;
}