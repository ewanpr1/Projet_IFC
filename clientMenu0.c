#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //getch
#include "clientMenu1.h"
#include "AcquisitionClient.h"

#include "menuManager.h"

#define NOMBRE_CHOIX_MENU 3

void clientMenu0(void)
{
        system("cls");

        int intChoice=0;

    do
    {
        printf("\n**** Bienvenue sur le menu Client ****\n\n");

        printf( "1/ Se connecter                        (saisir 1)\n"
                "2/ S'inscrire                          (saisir 2)\n"
                "3/ Retourner au menu principal         (saisir 3)\n");

        intChoice=menuManager(getch(),NOMBRE_CHOIX_MENU);

        while(intChoice==10)
        {
            printf("\n>>Veuillez re-saisir votre choix de menu");
            intChoice=menuManager(getch(),NOMBRE_CHOIX_MENU);
        }

        switch (intChoice)
        {
            case 1: system("cls");
                    /* demarrer la fonction "Connexion" */
                    AcquisitionClient(21);
                    clientMenu1();
                    break;

            case 2: system("cls");
                    /* demarrer la fonction "Inscription" */
                    AcquisitionClient(22);
                    clientMenu1();
                    break;

            case 3: system("cls"); /* afficher le menu principal*/
                    break;

            default:    printf("\n\n>> erreur: probleme switch menu caissier");
                        system("cls");
        }
    }
    while(intChoice!=NOMBRE_CHOIX_MENU);
}
