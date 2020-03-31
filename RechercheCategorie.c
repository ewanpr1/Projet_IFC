#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "AcquisitionProduits.h"
#include "menuManager.h"

#include "StructProduit.h"

#define MAX 20
#define NOMBRE_CHOIX_MENU 5

void RechercheCategorie(int nb_line,Produit ListeProduit[])
{
    int i=0,intChoice=0;
    char Choix[MAX];


    printf(">> Veuillez selectionner la categorie recherchee : \n");

    printf( "1/ Hifi                    (saisir 1)\n"
            "2/ Electromenager          (saisir 2)\n"
            "3/ Informatique            (saisir 3)\n"
            "4/ Telephonie              (saisir 4)\n"
            "5/ Gaming                  (saisir 5)\n");

    intChoice=menuManager(getch(),NOMBRE_CHOIX_MENU);

    while(intChoice==10)
        {
            printf("\n>>Veuillez re-saisir votre choix de menu");
            intChoice=menuManager(getch(),NOMBRE_CHOIX_MENU);
        }

    switch (intChoice)
        {
        case 1: system("cls");
                strcpy(Choix,"Hifi");
                break;

        case 2: system("cls");
                strcpy(Choix,"Electromenager");
                break;

        case 3: system("cls");
                strcpy(Choix,"Informatique");
                break;

        case 4: system("cls");
                strcpy(Choix,"Telephonie");
                break;

        case 5: system("cls");
                strcpy(Choix,"Gaming");
                break;

        default:    system("cls");
                    printf("\n\n>> erreur: probleme switch menu gestionnaire");
        }




    printf(">> Les produits de la categorie %s sont : \n\n",Choix);


    for(i=0;i<=nb_line;i++)
    {
        if(strcmp(Choix,ListeProduit[i].categorie)==0)
        {
            printf("ID : %s\n",ListeProduit[i].ID);
            printf("Nom : %s\n",ListeProduit[i].nom);
            printf("Prix : %s\n",ListeProduit[i].prix);
            printf("Caracteristiques : %s\n",ListeProduit[i].caract);
            printf("Stock : %s\n",ListeProduit[i].stock);
            printf("------------------\n\n");
        }
    }
}
