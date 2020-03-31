#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> //sleep

#define MAXI 500


void InscriptionClient()
{
    int nb_line=0,c,ID,k=0,i=0,test=0;
    char NOM[MAXI], PRENOM[MAXI], MDP[MAXI];

    FILE* fic = fopen("Clients.csv", "r+");

do
{
    //Acquisition du nom
    printf("Veuillez entrer votre nom : ");
    fflush(stdin);
    gets(NOM);

    //Test si le nom saisie contient que des lettres ou -
        for(i=0;i<strlen(NOM);i++)
        {
            strupr(NOM);
            if(!((NOM[i]>='A' && NOM[i]<='Z') || NOM[i]=='-'))
            {
                k++;
            }

        }
        if (k==0)
        {
        //Acquisition du prénom
        printf("\nVeuillez entrer votre prenom : ");
        fflush(stdin);
        gets(PRENOM);

        i=0;
        k=0;

        for(i=0;i<strlen(PRENOM);i++)
        {
            strlwr(PRENOM);
            //Test si le prénom saisie contient que des lettres ou -
            if(!((PRENOM[i]>='a' && PRENOM[i]<='z') || PRENOM[i]=='-'))
            {
                k++;
            }
        }
            if (k==0)
            {
                //Acquisition du mot de passe et vérification
                printf("\nVeuillez entrer votre mot de passe a 6 caracteres : ");
                fflush(stdin);
                gets(MDP);

                while(strlen(MDP)!=6)
                {
                    printf("\n> Erreur : Veuillez entrer votre mot de passe a 6 caracteres : ");
                    fflush(stdin);
                    gets(MDP);
                }

                rewind(fic);

                //Ecriture du profil du client dans le fichier Client
                while((c=getc(fic)) != EOF)
                {
                    if (c== '\n') ++nb_line;
                }

                //printf("\n%d",nb_line);

                ID=1013+nb_line;

                fprintf(fic,"\n%i;%s %s;%s",ID,NOM,PRENOM,MDP);

                test = 1;
            }
            else
            {
                printf("\n> Prenom invalide\n");
            }

        }
        else
        {
            printf("\n> Nom invalide\n");
        }

        fclose(fic);

}
while(test==0);

//Affichage de l'ID attitré au client

printf("\nVotre ID Client est le : %d, pensez a le noter !\n",ID);

Sleep(3500);

}
