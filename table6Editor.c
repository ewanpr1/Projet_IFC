#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXI 200

struct objet
{
    char a[MAXI];
    char b[MAXI];
    char c[MAXI];
    char d[MAXI];
    char e[MAXI];
    char f[MAXI];
};

typedef struct objet objet;



void table6Editor(FILE *file, char string[],int lineTarget,int columnTarget)
{
    int nbLine=0,eofTest, beforeSemicolon,numero;
    char tmpString[MAXI], tmpMemory[MAXI];
    objet objet[MAXI];

    rewind(file); //permet de se replacer en tout en haut du fichier

    //comptage du nombre de lignes dans le fichier et stockage dans la variable "nbLine"
    while((eofTest=getc(file)) != EOF)
    {
        if (eofTest== '\n') ++nbLine;
    }

    rewind(file); //permet de se replacer en tout en haut du fichier


    for(numero=0; numero<nbLine; numero++) //Pour chaque ligne utilisée du fichier
    {
        fgets(tmpString,MAXI,file);

        ///////////////////////////////////////////////

        //stockage de la propriete a de l'objet
        beforeSemicolon=0;
        while (tmpString[beforeSemicolon]!=';')
        {
            beforeSemicolon++;
        }
        strncpy(objet[numero].a,tmpString,beforeSemicolon);

        strcpy(tmpMemory,&tmpString[beforeSemicolon+1]);
        strcpy(tmpString,tmpMemory);

        ///////////////////////////////////////////////

        //stockage de la propriete b de l'objet
        beforeSemicolon=0;
        while (tmpString[beforeSemicolon]!=';')
        {
            beforeSemicolon++;
        }
        strncpy(objet[numero].b,tmpString,beforeSemicolon);

        strcpy(tmpMemory,&tmpString[beforeSemicolon+1]);
        strcpy(tmpString,tmpMemory);
        ///////////////////////////////////////////////

        //stockage de la propriete c de l'objet
        beforeSemicolon=0;
        while (tmpString[beforeSemicolon]!=';')
        {
            beforeSemicolon++;
        }
        strncpy(objet[numero].c,tmpString,beforeSemicolon);

        strcpy(tmpMemory,&tmpString[beforeSemicolon+1]);
        strcpy(tmpString,tmpMemory);

    ///////////////////////////////////////////////

        //stockage de la propriete d de l'objet
        beforeSemicolon=0;
        while (tmpString[beforeSemicolon]!=';')
        {
            beforeSemicolon++;
        }
        strncpy(objet[numero].d,tmpString,beforeSemicolon);

        strcpy(tmpMemory,&tmpString[beforeSemicolon+1]);
        strcpy(tmpString,tmpMemory);

    ///////////////////////////////////////////////

        //stockage de la propriete e de l'objet
        beforeSemicolon=0;
        while (tmpString[beforeSemicolon]!=';')
        {
            beforeSemicolon++;
        }
        strncpy(objet[numero].e,tmpString,beforeSemicolon);

        strcpy(tmpMemory,&tmpString[beforeSemicolon+1]);
        strcpy(tmpString,tmpMemory);

        ///////////////////////////////////////////////

        //stockage de la propriete f de l'objet
        beforeSemicolon=0;
        while (tmpString[beforeSemicolon]!='\n')
        {
            beforeSemicolon++;
        }
        strncpy(objet[numero].f,tmpString,beforeSemicolon);

        strcpy(tmpMemory,&tmpString[beforeSemicolon+1]);
        strcpy(tmpString,tmpMemory);
    }

    //modification de la "cellule" dans la structure
    lineTarget--;
    switch(columnTarget)
    {
        case 1: strcpy(objet[lineTarget].a,string);
                break;

        case 2: strcpy(objet[lineTarget].b,string);
                break;

        case 3: strcpy(objet[lineTarget].c,string);
                break;

        case 4: strcpy(objet[lineTarget].d,string);
                break;

        case 5: strcpy(objet[lineTarget].e,string);
                break;

        case 6: strcpy(objet[lineTarget].f,string);
                break;
    }

    rewind(file); //permet de se replacer en tout en haut du fichier

    //copie de la structure dans le fichier
    for(numero=0; numero<nbLine; numero++) //Pour chaque ligne utilisée du fichier
    {
        fprintf(    file,
                    "%s;%s;%s;%s;%s;%s"
                    "\n",
                    objet[numero].a,
                    objet[numero].b,
                    objet[numero].c,
                    objet[numero].d,
                    objet[numero].e,
                    objet[numero].f);
    }
}
