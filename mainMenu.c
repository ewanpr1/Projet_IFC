#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //getch

#include "menuManager.h"
#include "clientMenu0.h"
#include "gestMenu1.h"
#include "caissierMenu1.h"


void mainMenu(void)
{
    int intChoice=0;

    do
    {
        printf("\n***Menu Principal***\n\n");

        printf("> Vous etes : \n\n");

        printf( "1/ Gestionnaire    (saisir 1)\n"
                "2/ Caissier        (saisir 2)\n"
                "3/ Client          (saisir 3)\n"
                "4/ Quitter         (saisir 4)\n");

        intChoice=menuManager(getch(),4);

        while(intChoice==10)
        {
            printf("\n>> Erreur: Veuillez saisir une valeur proposee dans le menu\n");
            intChoice=menuManager(getch(),4);
        }

        switch (intChoice)
        {
            case 1: system("cls");
                    gestMenu1();/* Afficher le menu gestionnaire */
                    break;

            case 2: system("cls");
                    caissierMenu1();/* Afficher le menu caissier */
                    break;

            case 3: system("cls");
                    clientMenu0(); /* Afficher le menu client */
                    break;

            case 4: system("cls"); /* quitter le programme*/
                    break;

            default:    system("cls");
                        printf("\n\n>> erreur: probleme switch menu principal");

        }

    }
    while(intChoice!=4);
}
