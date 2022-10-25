#include <stdio.h>

int main() 
{

    int a = 10;
    int b = 11;
    int c = 11;
   


    if (a < b) // c'est une condition et pas une comparaison, bien mettre crochet pour tout prendre en compte sinon ne prend que la premiere ligne
    {   
        if (b == c) // (si) possibilite d'ajouter des sous-condition 
        { 
            printf("b = c\n");
        }
        printf("La condition");
        printf(" est vraie\n");
    } 
    
    else if (b == c) // (sinon si) possibilite d'ajouter condition intermediaire
    {
        printf("La condition est vraie\n");
    }
    else // (sinon)
    {
        printf("La condition est fausse\n");
    }    
  
    switch (a) // permet de comparer a et de switch en fonction de sa valeur, utilisable que pour des égalité, pas de inférieur supérieur etc
    {
        case 0:
            printf("a vaut 0\n");
            break; // break obligatoire pour sortir du switch (une seule réponse possible)
        
      if (a < b) // c'est une condition et pas une comparaison, bien mettre crochet pour tout prendre en compte sinon ne prend que la premiere ligne
    {     
        if (b == c) // (si) possibilite d'ajouter des sous-condition 
        { 
            printf("b = c\n");
        }
        printf("La condition");
        printf(" est vraie\n");
   
    }      case 10:
            printf("a vaut 10\n");
            break;
        
        default:
            printf("Aucune idee de la valeur de a\n");

    }
    
    
    
    
    // printf("La condition est fausse\n");

    // printf("a = %d\n", a);
    // printf("b = %d\n", b);
    // printf("c = %d\n", c);
    // printf("res = %d\n", res);
    // printf("res2 = %d\n", res2);
    // printf("res3 = %d\n", res3);
    // printf("res4 = %d\n", res4);
    // printf("res5 = %d\n", res5);
    // printf("res6 = %d\n", res6);
    // printf("res7 = %.15f\n", res7);
    

    return 0;
}