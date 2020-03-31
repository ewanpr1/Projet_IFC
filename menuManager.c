/*
****
Fonction charToInt
->  Transforme les caractère '1' , '2' ,..., '9' en entier correcpondant 1 , 2 ,..., 9
    Utile pour la gestion des menus notamment
->entrees:
    char: numero du menu acquis grace a la fonction getch()
    int: nombre de menus possibles
->sorties:
    Pour charChoice '1','2',...,'9':
        int correspondant au numero du menu acquis grace à la fonction getch()
    Pour charChoice différent de '1','2',...,'9':
        int=10
    Si le numero de menu demande est superieur au nombre de menus existant (gerer par testMenu):
        int=11
****
*/

#include <stdio.h>
#include <stdlib.h>

int testMenu(int,int);

int menuManager(char charChoice, int nbMenu)
{
    switch (charChoice)
    {
        case '1':   return testMenu(1,nbMenu);
                    break;

        case '2':   return testMenu(2,nbMenu);
                    break;

        case '3':   return testMenu(3,nbMenu);
                    break;

        case '4':   return testMenu(4,nbMenu);
                    break;

        case '5':   return testMenu(5,nbMenu);
                    break;

        case '6':   return testMenu(6,nbMenu);
                    break;

        case '7':   return testMenu(7,nbMenu);
                    break;

        case '8':   return testMenu(8,nbMenu);
                    break;

        case '9':   return testMenu(9,nbMenu);
                    break;

        default:    return 10;
    }
}

int testMenu(int numeroMenu,int nbMenu)
{
    if(numeroMenu>nbMenu)
    {
        printf("\n\n>>erreur: le menu demande n'existe pas");
        return 10;
    }
    else
    {
        return numeroMenu;
    }
}
