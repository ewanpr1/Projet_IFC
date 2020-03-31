#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "AcquisitionProduits.h"
#include "StructProduit.h"

/*Fonction qui permet de rechercher un produit grâce à l'ID*/

void RechercheProduit(int nb_line,Produit ListeProduit[])
{
    char Acquisition[MAXI];
    char IDProduit[7];
    int k=0;

    printf("Veuillez saisir l'ID a 6 chiffres du produit recherche : ");
    fflush(stdin);
    gets(Acquisition);

        while (strlen(Acquisition)!=6)
        {
            printf("\n>>Erreur : Veuillez saisir l'ID a 6 chiffres du produit recherche : ");
            fflush(stdin);
            gets(Acquisition);
            system("cls");
        }

    strcpy(IDProduit,Acquisition);

    while (strcmp(IDProduit,ListeProduit[k].ID)!=0 && k<=nb_line)
    {
        k=k+1;
    }

    if (k>nb_line)
    {
        system("cls");
        printf("\nLe produit que vous recherchez n'existe pas");
    }
    else
    {
        system("cls");
        printf(">> Le produit recherche est : \n\n");

        printf("ID : %s\n",ListeProduit[k].ID);
        printf("Categorie : %s\n",ListeProduit[k].categorie);
        printf("Nom : %s\n",ListeProduit[k].nom);
        printf("Prix : %s\n",ListeProduit[k].prix);
        printf("Caracteristiques : %s\n",ListeProduit[k].caract);
        printf("Stock : %s\n",ListeProduit[k].stock);
    }
}
