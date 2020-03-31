#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //getch
#include "clientMenu2.h"
#include "AcquisitionClient.h"

#include "menuManager.h"

#define NOMBRE_CHOIX_MENU 2

void clientMenu1(void)
{
    int intChoice=0;

    do
    {
        system("cls");
        printf("> Vous etes connecte en tant que Client\n\n\n");

        printf( "1/ Faire mes courses                           (saisir 1)\n"
                "2/ Retourner au menu principal                 (saisir 2)\n");

        intChoice=menuManager(getch(),NOMBRE_CHOIX_MENU);

        while(intChoice==10)
        {
            printf("\n>>Veuillez re-saisir votre choix de menu");
            intChoice=menuManager(getch(),NOMBRE_CHOIX_MENU);
        }

        switch (intChoice)
        {
            case 1: system("cls");
                    clientMenu2();
                    /* demarrer la fonction "rechercher un produit" */
                    break;

            case 2: system("cls"); /* afficher le menu principal*/
                    break;

            default:    printf("\n\n>> erreur: probleme switch menu client");
                        system("cls");
        }
    }
    while(intChoice!=NOMBRE_CHOIX_MENU);
}

