#include <stdio.h>
#include <stdlib.h>

void printBank(void)
{
    char stringSolde[100];

    //lecture du solde dans le fichier et stockage dans stringSolde
    FILE *fileBank = fopen("bank.txt","r");
    fscanf(fileBank,"%s",stringSolde);
    fclose(fileBank);

    printf("\nSolde du compte en banque: %s",stringSolde);
}
