#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>


// inverse le string 'str' de longueur 'len'
void reverse(char *str, int len)
{
    int i=0, j=len-1, temp;
    while (i<j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++; j--;
    }
}

 /*
 Converti un entier donné x en une chaine de caractere str[].
 D est le nombre de digits requis en sortie.
 Si d est plus grande que le nombre de digits d' x,
 alors 0s sont ajoutés au début
 */

int intToStr(int x, char str[], int d)
{
    int i = 0;
    while (x)
    {
        str[i++] = (x%10) + '0';
        x = x/10;
    }

/*
Si le nombre de digits requis est plus grand,
alors, ajout 0s au début.
*/
    while (i < d)
        str[i++] = '0';

    reverse(str, i);
    str[i] = '\0';
    return i;
}

// Convertis un float en string
void ftoa(float n, char *res, int afterpoint)
{
    char tmp[500];

    // Extrait la partie entière
    int ipart = (int)abs(n);

    // Extrait la partie flottante
    float fpart = abs(n) - (float)ipart;

    // Converti la partie entière en string
    int i = intToStr(ipart, tmp, 0);

    // check for display option after point
    if (afterpoint != 0)
    {
        tmp[i] = '.';  // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter is needed
        // to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);

        intToStr((int)fpart, tmp + i + 1, afterpoint);
    }

    //gestion d'une conversion d'un float negatif en chaine de caracteres
    if(n<0)
    {
        res[0]='-';
        strcpy(&res[1],tmp);

    }
    else
    {
        strcpy(res,tmp);
    }
}
