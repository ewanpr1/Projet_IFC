#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //getch
#include "AcquisitionProduits.h"
#include "StructProduit.h"
#include "menuManager.h"
#include "AjoutPanier.h"

#define NOMBRE_CHOIX_MENU 4

void Facturation(int nb_line, Produit ListeProduit[])
{
    int intChoice;

    printf("*** Menu Facturation ***\n\n");

    do
    {
    printf( "1/ Ajouter un produit au panier                    (saisir 1)\n"
            "2/ Rechercher un produit                           (saisir 2)\n"
            "3/ Rechercher une categorie de produits            (saisir 3)\n"
            "4/ Retourner au menu principal                     (saisir 4)\n");

    intChoice=menuManager(getch(),NOMBRE_CHOIX_MENU);

        while(intChoice==10)
        {
            printf("\n>>Veuillez re-saisir votre choix de menu");
            intChoice=menuManager(getch(),NOMBRE_CHOIX_MENU);
        }

        switch (intChoice)
        {
            case 1: system("cls");
                    AjoutPanier(nb_line,ListeProduit);
                    /* demarrer la fonction "ajout d'un produit au panier" */
                    break;

            case 2: system("cls");
                    AcquisitionProduits(11);
                    /* demarrer la fonction "rechercher un produit" */
                    break;

            case 3:
                    system("cls");
                    AcquisitionProduits(12);
                    /* demarrer la fonction "rechercher une categorie de produit" */
                    break;

            case 4:
                    system("cls");
                    /* Retour au menu précédant */
                    break;

            default:    printf("\n\n>> erreur: probleme switch menu Facturatoion");
                        system("cls");
        }
    }
    while(intChoice!=NOMBRE_CHOIX_MENU);

}


