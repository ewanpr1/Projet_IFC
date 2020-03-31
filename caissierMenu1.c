#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //getch

#include "menuManager.h"
#include "AcquisitionClient.h"
#include "AcquisitionProduits.h"
#include "passwordManager.h"

#define NOMBRE_CHOIX_MENU 5

void caissierMenu1(void)
{
    int intChoice=0;


    printf("\n**** Bienvenue sur le menu Caissier ****\n\n");

    passwordManager("100","Caissier");

    do
    {
        system("cls");
        printf(">> Vous etes connecte en tant que Caissier\n\n\n");

        printf( "1/ Rechercher un produit                       (saisir 1)\n"
                "2/ Rechercher une categorie de produit         (saisir 2)\n"
                "3/ Inscire un client                           (saisir 3)\n"
                "4/ Facturer des produits                       (saisir 4)\n"
                "5/ Retourner au menu principal                 (saisir 5)\n");

        intChoice=menuManager(getch(),NOMBRE_CHOIX_MENU);

        while(intChoice==10)
        {
            printf("\n>>Veuillez re-saisir votre choix de menu");
            intChoice=menuManager(getch(),NOMBRE_CHOIX_MENU);
        }

        switch (intChoice)
        {
            case 1: system("cls");
                    AcquisitionProduits(11);
                    /* demarrer la fonction "rechercher un produit" */
                    break;

            case 2: system("cls");
                    AcquisitionProduits(12);
                    /* demarrer la fonction "rechercher une categorie de produit" */
                    break;

            case 3:
                    system("cls");
                    AcquisitionClient(22);
                    /* demarrer la fonction "inscrire un client" */
                    break;

            case 4:
                    system("cls");
                    AcquisitionProduits(14);
                    /* demarrer la fonction "facturer des produits" */
                    break;

            case 5: system("cls"); /* afficher le menu principal*/
                    break;

            default:    printf("\n\n>> erreur: probleme switch menu caissier");
                        system("cls");
        }
    }
    while(intChoice!=NOMBRE_CHOIX_MENU);
}

