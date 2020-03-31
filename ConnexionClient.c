#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "StructClient.h"
#include "AcquisitionClient.h"

#define MAXI 200


void ConnexionClient(int nb_line, Client ListeClient[])
{
    char IDClient[MAXI],MDPClient[MAXI];
    int i=0,connexion=0;

    do{
            //Acquisition ID client avec test
            printf("\nVeuillez saisir votre ID Client a 4 chiffres :  ");
            fflush(stdin);
            gets(IDClient);

            while (strlen(IDClient)!=4)
            {
                printf("\n>>Erreur : Veuillez saisir un ID a 4 chiffres : ");
                fflush(stdin);
                gets(IDClient);
            }

        while (strcmp(IDClient,ListeClient[i].ID)!=0 && i<=nb_line)
            {
                i=i+1;
            }

        if (i>nb_line)
        {
            printf("\nL'ID Client n'existe pas");
            connexion=0;
        }
        else
        {
            //Si l'ID client existe, acquisition du mot de passe et test
            printf("\nVeuillez saisir votre mot de passe a 6 caracteres :  ");
            fflush(stdin);
            gets(MDPClient);

            while (strlen(MDPClient)!=6)
            {
                printf("\n>>Erreur : Veuillez saisir un mot de passe a 6 caracteres : ");
                fflush(stdin);
                gets(MDPClient);
            }

            if (strcmp(MDPClient,ListeClient[i].MDP)!=0)
            {

                printf("\n>>Erreur : Mot de passe incorrect");
                connexion=0;
            }
            else
            {
                connexion=1;
            }
        }
    }
    while(connexion!=1);
}
