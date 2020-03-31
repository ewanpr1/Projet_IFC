#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <windows.h> //sleep

#define MAX_LEN 128

void print_image(FILE *);
void test_file(FILE *);

void startupMessage(void)
{
    int i,j=30;
    FILE *fileWelcome = fopen("welcomeMessage.txt","r");
    FILE *fileLogo = fopen("logo.txt","r");

    while(j>0)
    {
        for(i=j;i>0;i--)
        {
            printf("\n");
        }
        print_image(fileWelcome);
        Sleep(10);
        j--;
        system("cls");
    }
    print_image(fileWelcome);
    print_image(fileLogo);

    test_file(fileWelcome);
    test_file(fileLogo);

    fclose(fileWelcome);
    fclose(fileLogo);

    getch();
    system("cls");
}

void print_image(FILE *FILE)
{
    char read_string[MAX_LEN];

    while(fgets(read_string,sizeof(read_string),FILE) != NULL)
    {
        printf("%s",read_string);
    }
    rewind(FILE);
}

void test_file(FILE *file)
{
    if(file == NULL)
    {
    printf(">> Erreur: impossible d'ouvrir le fichier");
    }
}
