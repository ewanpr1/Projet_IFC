#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ftoa.h"

#define MAXI 500

void bankManager(float difArgent)
{
    char stringSolde[MAXI]="";
    float floatSolde=0;

    //lecture du solde dans le fichier et stockage dans stringSolde
    FILE *fileBank = fopen("bank.txt","r");
    fscanf(fileBank,"%s",stringSolde);
    fclose(fileBank);

    //conversion de stringSolde en float correspondant
    floatSolde=atof(stringSolde);

    //RAZ stringSolde
    strcpy(stringSolde,"");

    //Calcul du nouveau solde
    floatSolde=floatSolde+difArgent;

    //Conversion du nouveau solde en chaine de caracteres
    ftoa(floatSolde,stringSolde,3);

    //Stockage du nouveau solde dans le fichier
    fileBank = fopen("bank.txt","w");
    fprintf(fileBank,"%s",stringSolde);
    fclose(fileBank);
}
