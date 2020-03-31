#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void passwordManager(char pw[],char user[])
{
    char userEntry[100];

    printf("Veuillez saisir le mot de passe %s :  ",user);
    scanf("%s",userEntry);

    while (strcmp(userEntry,pw)!=0)
        {

            printf( "\n>> Erreur : mot de passe incorrect\n"
                    "Veuillez saisir le mot de passe %s :  ",user);
            scanf("%s",userEntry);
        }
    system("cls");
}











 /*while (intPassword != 100)
    {
        printf( "\n\n>> Erreur : mot de passe incorrect\n"
                "Veuillez saisir le mot de passe Gestionnaire :  ");
        scanf("%d",&intPassword);
    }
    system("cls");*/
