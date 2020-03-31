#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "alimStock.h"
#include "RechercheCategorie.h"
#include "RechercheProduit.h"
#include "Facturation.h"


/*Fonction qui permet de lire dans le fichier Produit et de lire tous les profils pour les stocker dans la structure Produit*/

void AcquisitionProduits(int Choice)
{
    char tableau[MAXI],mem[MAXI];
    Produit ListeProduit[MAXI];
    int c;
    int i=0,k=0,nb_line=0;
    FILE* fic = fopen("Produits.csv", "r");

    //comptage du nombre de lignes dans le fichier "Produits" et stockage dans la variable "nb_line"
    while((c=getc(fic)) != EOF)
    {
        if (c== '\n') ++nb_line;
    }

    rewind(fic); //permet de se replacer en tout en haut du fichier

    for(k=0;k<nb_line;k++) //Pour chaque ligne utilisée du fichier
    {


        fgets(tableau,MAXI,fic); //lecture de la premiere ligne du fichier et stockage dans "tableau"

        //stockage de l'ID
        i=0;
        while (tableau[i]!=';') //comptage du nombre de caractères avant le premier ;
        {
            i++;
        }
        strncpy(ListeProduit[k].ID,&tableau[0],i); //copie de la 1ere information de tableau dans l'ID (structure)

        strcpy(mem,&tableau[i+1]);
        strcpy(tableau,mem);


        ///////////////////////////////////////////////

        //stockage de la catégorie
        i=0;
        while (tableau[i]!=';')
        {
            i++;
        }
        strncpy(ListeProduit[k].categorie,&tableau[0],i);

        strcpy(mem,&tableau[i+1]);
        strcpy(tableau,mem);

        ////////////////////////////////////////////

        //stockage du nom
        i=0;
        while (tableau[i]!=';')
        {
            i++;
        }
        strncpy(ListeProduit[k].nom,&tableau[0],i);

        strcpy(mem,&tableau[i+1]);
        strcpy(tableau,mem);

        ////////////////////////////////////////////

        //stockage du prix
        i=0;
        while (tableau[i]!=';')
        {
            i++;
        }
        strncpy(ListeProduit[k].prix,&tableau[0],i);

        strcpy(mem,&tableau[i+1]);
        strcpy(tableau,mem);


        ////////////////////////////////////////////

        //stockage des caracteristiques
        i=0;
        while (tableau[i]!=';')
        {
            i++;
        }
        strncpy(ListeProduit[k].caract,&tableau[0],i);

        strcpy(mem,&tableau[i+1]);
        strcpy(tableau,mem);

        ////////////////////////////////////////////

        //stockage de la quantité
        i=0;
        while (tableau[i]!=';')
        {
            i++;
        }
        strncpy(ListeProduit[k].stock,&tableau[0],i);

        strcpy(mem,&tableau[i+1]);
        strcpy(tableau,mem);

    }

    fclose(fic);

    switch(Choice)
    {
        case 11:    system("cls");
                    //Appel à la fonction "RechercheProduit"
                    RechercheProduit(nb_line,ListeProduit);
                    getch();
                    system("cls");
                    break;

        case 12:    system("cls");
                    //Appel à la fonction "RechercheCategorie"
                    RechercheCategorie(nb_line,ListeProduit);
                    getch();
                    system("cls");
                    break;

        case 13:    alimStock(nb_line,ListeProduit);
                    //Appel à la fonction "alimStock"
                    break;

        case 14:    Facturation(nb_line,ListeProduit);
                    //Appel à la fonction "Facturation"
                    break;
    }
}
