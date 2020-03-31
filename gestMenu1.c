#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //getch
#include <string.h>

#include "menuManager.h"
#include "passwordManager.h"
#include "AcquisitionProduits.h"
#include "alimStock.h"
#include "printBank.h"


#define NOMBRE_CHOIX_MENU 5

void gestMenu1(void)
{
    int intChoice1=0,intChoice2=0;

    printf("\n**** Bienvenue sur le menu Gestionnaire ****\n\n");

    passwordManager("100","Gestionnaire");

    do
    {
        system("cls");
        printf(">> Vous etes connecte en tant que Gestionnaire\n\n\n");

        printf( "1/ Rechercher un produit                       (saisir 1)\n"
                "2/ Rechercher une categorie de produit         (saisir 2)\n"
                "3/ Alimenter le stock                          (saisir 3)\n"
                "4/ Afficher le solde du compte en banque       (saisir 4)\n"
                "5/ Retourner au menu principal                 (saisir 5)\n");

        intChoice1=menuManager(getch(),NOMBRE_CHOIX_MENU);

        while(intChoice1==10)
        {
            printf("\n>>Veuillez re-saisir votre choix de menu");
            intChoice1=menuManager(getch(),NOMBRE_CHOIX_MENU);
        }

        switch (intChoice1)
        {
            case 1: system("cls");
                    AcquisitionProduits(11); /* demarrer la fonction "rechercher un produit" */
                    break;

            case 2: system("cls");
                    AcquisitionProduits(12); /* demarrer la fonction "rechercher une categorie de produit" */
                    break;

            case 3: system("cls");
                    do
                    {
                        AcquisitionProduits(13);
                        do
                        {
                            system("cls");
                            printf( "1/ Modifier la quantite d'un produit a nouveau (saisir 1)\n"
                                    "2/ Retour au menu gestionnaire                 (saisir 2)\n");

                            intChoice2=menuManager(getch(),2);
                            system("cls");
                        }
                        while(intChoice2==10);
                    }
                    while(intChoice2==1);
                    system("cls");/* demarrer la fonction "alimenter le stock" */
                    break;

            case 4: system("cls");
                    printBank();
                    printf("\n\n(Appuyez sur une touche pour passer)");
                    getch();
                    break;

            case 5: system("cls"); /* afficher le menu principal*/
                    break;

            default:    system("cls");
                        printf("\n\n>> erreur: probleme switch menu gestionnaire");
        }
    }
    while(intChoice1!=NOMBRE_CHOIX_MENU);

}
