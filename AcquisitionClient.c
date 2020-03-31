#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "StructClient.h"
#include "ConnexionClient.h"
#include "InscriptionClient.h"

#define MAXI 200

/*Fonction qui permet de lire dans le fichier Client et de lire tous les profils pour les stocker dans la structure client*/

void AcquisitionClient(int Choice)
{
    char tableau[MAXI],mem[MAXI];
    Client ListeClient[MAXI];
    int c;
    int i=0,k=0,nb_line=0;
    FILE* fic = fopen("Clients.csv", "rt");

    while((c=getc(fic)) != EOF)
    {
        if (c== '\n') ++nb_line;
    }

    rewind(fic);

    for(k=0;k<nb_line;k++)
    {

    i=0;
    fgets(tableau,MAXI,fic);

    while (tableau[i]!=';')
    {
        i++;
    }
    strncpy(ListeClient[k].ID,&tableau[0],i);


    strcpy(mem,&tableau[i+1]);
    strcpy(tableau,mem);


    ///////////////////////////////////////////////

    i=0;
    while (tableau[i]!=';')
    {
        i++;
    }
    strncpy(ListeClient[k].NOM,&tableau[0],i);

    strcpy(mem,&tableau[i+1]);
    strcpy(tableau,mem);

    ////////////////////////////////////////////

    strncpy(ListeClient[k].MDP,&tableau[i+1],6);
    ListeClient[k].ID[6]='\0';
    }

    fclose(fic);

    if (Choice==21)
    {
        //Appel à la fonction "ConnexionClient"
        ConnexionClient(nb_line,ListeClient);
    }
    else if (Choice==22)
    {
        //Appel à la fonction "InscriptionClient"
        InscriptionClient();
    }
}
