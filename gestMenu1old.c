#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //getch
#include <string.h>

#include "menuManager.h"
#include "passwordManager.h"
#include "AcquisitionProduits.h"


#define NOMBRE_CHOIX_MENU 4

void gestMenu1(void)
{
    //int intPassword,
    int intChoice=0;

    printf("\n**** Bienvenue sur le menu Gestionnaire ****\n\n");

    passwordManager("100","Gestionnaire");

    do
    {
        printf("\n\n>> Vous etes connecte en tant que Gestionnaire\n\n\n");

        printf( "1/ Rechercher un produit                       (saisir 1)\n"
                "2/ Rechercher une categorie de produit         (saisir 2)\n"
                "3/ Afficher les statistiques                   (saisir 3)\n"
                "4/ Retourner au menu principal                 (saisir 4)\n");

        intChoice=menuManager(getch(),NOMBRE_CHOIX_MENU);

        while(intChoice==10)
        {
            printf("\n>>Veuillez re-saisir votre choix de menu");
            intChoice=menuManager(getch(),NOMBRE_CHOIX_MENU);
        }

        switch (intChoice)
        {
            case 1: system("cls");
                    AquisitionProduits(11);
                    /* demarrer la fonction "rechercher un produit" */
                    break;

            case 2: system("cls");
                    AquisitionProduits(12);
                    /* demarrer la fonction "rechercher une categorie de produit" */
                    break;

            case 3:
                    system("cls");
                    /* demarrer la fonction "afficher les statistiques" */
                    break;

            case 4: system("cls"); /* afficher le menu principal*/
                    break;

            default:    system("cls");
                        printf("\n\n>> erreur: probleme switch menu gestionnaire");
        }
    }
    while(intChoice!=NOMBRE_CHOIX_MENU);

}
