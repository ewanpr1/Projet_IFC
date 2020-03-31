#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "StructProduit.h"

#include "AcquisitionProduits.h"
#include "menuManager.h"
#include "bankManager.h"
#include "table6Editor.h"


void alimStock(int nbLine,Produit *listeProduits) //Cette fonction permet au gestionnaire d'augmenter le stock d'un produit.
{
    char productID[7], charStockFin[MAXI];
    int  matchCounter=0, difProduct,stockIni,stockFin,action,valider;
    float difArgent,stringSolde;


    difProduct=0;
    difArgent=0;
    //demande de saisie de l'ID produit
    printf("Veuillez saisir l'ID a 6 chiffres du produit dont vous souhaite modifier la quantite : ");
    fflush(stdin);
    gets(productID);

    //contrôle de la longueur de l'ID entré par l'utilisateur
    while (strlen(productID)!=6)
    {
        printf("\n>>Erreur : Veuillez saisir l'ID a 6 chiffres: ");
        fflush(stdin);
        gets(productID);
    }

    while (strcmp(productID,listeProduits[matchCounter].ID)!=0 && matchCounter<=nbLine)
    {
        matchCounter++;
    }

    if (matchCounter>nbLine)
    {
        printf("\nLe produit que vous recherchez n'existe pas");
    }
    else
    {
        do
        {
            system("cls");
            printf("\n\n>> Produit trouve ! : \n\n");

            printf("ID : %s\n",listeProduits[matchCounter].ID);
            printf("Nom : %s\n",listeProduits[matchCounter].nom);
            printf("Prix : %s\n",listeProduits[matchCounter].prix);
            printf("Stock : %s\n",listeProduits[matchCounter].stock);


            stockIni=atoi(listeProduits[matchCounter].stock);
            stockFin=stockIni+difProduct;

            printf("\nCombien de produits souhaitez vous ajouter ?");
            printf("\n\nNombre de produits initial:   %i",stockIni);
            if(difProduct>=0)
            {
                printf("\nNombre de produits a ACHETER pour alimenter le stock: %i",difProduct);
            }
            else
            {
                printf("\nNombre de produits a REVENDRE pour vider le stock: %i",abs(difProduct));
            }
            printf("\nNombre de produits final:     %i",stockFin);

            printf( "\n\n"
                    "1/ Incrementer un stock                                (saisir +)\n"
                    "2/ Decrementer le stock                                (saisir -)\n"
                    "3/ Valider le changement et proceder a la transaction  (saisir ENTRER)\n"
                    "4/ Retourner au menu precedent                         (saisir 4)\n");

            do
            {
                action=0;
                valider=0;
                switch(getch())
                {
                    case '-':   if(stockFin>0)
                                {
                                    difProduct--;

                                }
                                else
                                {
                                    printf("\n\n"
                                           "\n>>Erreur: votre stock ne peut pas devenir negatif"
                                           "\n\nAppuyez sur une touche pour passer l'erreur");
                                    getch();
                                }
                                action=1;
                                break;

                    case '+':   difProduct++;
                                action=1;
                                break;

                    case '\r':  action=3;
                                break;

                    case '4' :  action=4;
                                break;

                    default:    action=0;
                }
            }
            while(action==0);
        }
        while(action==1);

        if(action==3)
        {
            system("cls");
            if(difProduct>=0)
            {
                difArgent=atof(listeProduits[matchCounter].prix)*(-difProduct);
                printf( "Vous vous appretez a APPROVISIONNER le stock"
                        "\n\nNombre de produits a ACHETER pour APPROVISIONNER le stock: %i"
                        "\nCout d'achat: %.2f eur"
                        ,difProduct,-difArgent);

            }
            else
            {
                difArgent=atof(listeProduits[matchCounter].prix)*abs(difProduct);
                printf( "Vous vous appretez a VIDER le stock"
                        "\nNombre de produits a REVENDRE pour VIDER le stock: %i"
                        "\nBenefices de revente: %.2f eur"
                        ,-difProduct,difArgent);

            }

            do
            {
                printf( "\n\n"
                        "1/ Valider definitivement la transaction   (saisir ENTRER)\n"
                        "2/ Annuler l'operation                     (saisir 0)");

                switch(getch())
                {
                    case '\r':  valider=0;
                                break;

                    case '0':   valider=1;
                                break;

                    default:    valider=2;
                }
            }
            while(valider==2);

            if(valider==0)
            {
                bankManager(difArgent); // Modifie le solde du compte bancaire en fonction de l'argent gagné/dépensé

                FILE *fic = fopen("Produits.csv", "r+");
                table6Editor(fic,itoa(stockFin,charStockFin,10),matchCounter+1,6); //modifie la quantité dans le fichier produits
                fclose(fic);
            }
        }
    }
}
