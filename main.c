#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#include "startupMessage.h"
#include "fullScreenOnOff.h"
#include "mainMenu.h"
#include "color.h"

#include "table6Editor.h"


int main(int argc, char* argv[])
{
    color(0,15);
    fullScreenOnOff();
    startupMessage();

    mainMenu();

    fullScreenOnOff();
    return 0;
}



// vider le buffer fflush(stdin); ??

