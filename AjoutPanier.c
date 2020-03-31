#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h> //getch

#define MAXI 200
#define NOMBRE_CHOIX_MENU 2

#include "AcquisitionProduits.h"
#include "StructProduit.h"
#include "StructPanier.h"
#include "menuManager.h"
#include "bankManager.h"
#include "table6Editor.h"

/*A Faire :
une structure panier pour avoir la quantité achetée         fait
Regarder si la quantité demandée est inférieure au stock    fait
transformer char en int : atoi(char)                        fait*/

void AjoutPanier(int nb_line, Produit ListeProduit[])
{
    char Acquisition[MAXI];
    char IDProduit[7],MEM[MAXI];
    Panier Panier[MAXI];
    int k=0,intChoice,test=0,quantite=0,i=-1,j=0,stock;
    float somme=0, prix=0;
    do
    {
        k=0;
        i++;
        printf("Veuillez saisir l'ID a 6 chiffres du produit que vous souhaitez acheter : ");
        fflush(stdin);
        gets(Acquisition);

            while (strlen(Acquisition)!=6)
            {
                printf("\n>>Erreur : Veuillez saisir l'ID a 6 chiffres du produit que vous souhaitez acheter : ");
                fflush(stdin);
                gets(Acquisition);
            }

            //Aquisition ID produit

        strcpy(IDProduit,Acquisition);

        while (strcmp(IDProduit,ListeProduit[k].ID)!=0 && k<=nb_line)
        {
            k=k+1;
        }

        //Recherche existence du produit

        if (k>nb_line)
        {
            printf("\nLe produit que vous recherchez n'existe pas");
        }
        else
        {
            //Copie des caractéristiques du produit dans la structure Panier

            strcpy(Panier[i].ID,ListeProduit[k].ID);
            strcpy(Panier[i].caract,ListeProduit[k].caract);
            strcpy(Panier[i].categorie,ListeProduit[k].categorie);
            strcpy(Panier[i].nom,ListeProduit[k].nom);
            strcpy(Panier[i].prix,ListeProduit[k].prix);
            strcpy(Panier[i].stock,ListeProduit[k].stock);

            printf("\nSaisissez la quantite que vous voulez acheter inferieur a %s  : ",Panier[i].stock);
            fflush(stdin);
            gets(Panier[i].quantite);

            //Demande de la quantité acheté et vérification qu'elle ne dépasse pas la quantité en stock

            while (atoi(Panier[i].stock),atoi(Panier[i].quantite)<=0)
            {
            printf("\n>> Erreur : La quantite en stock n'est pas suffisante, veuillez saisir une valeur inferieur a %s : ",Panier[i].stock);
            fflush(stdin);
            gets(Panier[i].quantite);
            }

            stock=atoi(Panier[i].stock)-atoi(Panier[i].quantite);
            itoa(stock,MEM,10);

            FILE *fic = fopen("Produits.csv", "r+");
            table6Editor(fic,MEM,i+1,6); //modifie la quantité dans le fichier produits
            fclose(fic);


            //Demande Si ajout d'autre produits au Panier ou si finalisation de l'achat

            intChoice=0;


            do
            {
                printf( "1/ Ajouter un autre produit au panier          (saisir 1)\n"
                        "2/ Finaliser l'achat                           (saisir 2)\n");
                fflush(stdin);
                intChoice=menuManager(getch(),NOMBRE_CHOIX_MENU);

                while(intChoice==10)
                {
                    printf("\n>>Veuillez re-saisir votre choix de menu");
                    intChoice=menuManager(getch(),NOMBRE_CHOIX_MENU);
                }

                switch (intChoice)
                {
                    case 1: system("cls");
                            test=0;
                            break;

                    case 2: system("cls");
                            test=1;
                            break;

                    default:    printf("\n\n>> erreur: probleme switch menu Facturatoion");
                                system("cls");
                }
            }
            while(intChoice<=0 || intChoice>2);

        }
    }
    while(test==0);

    system("cls");

    //Finalisation de l'achat avec récapiutulatif

    printf("\n>> Voici le recapitulatif de votre panier :\n");

    for (j=0;j<=i;j++)
    {
            printf("\n Quantite : %s   |   %s",Panier[j].quantite,Panier[j].nom);
            prix=atof(Panier[j].prix);
            quantite=atoi(Panier[j].quantite);
            somme = somme + prix*quantite;
    }

    printf("\n\n>> Le prix total du panier est : %.2f euros", somme);

    //Affichage du prix total et payement

    printf("\n\n> Appuyez sur une touche pour payer");
    fflush(stdin);
    getch();
    bankManager(somme);

    system("cls");
}
