#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.c>
#include <time.h>
#include "addmusic.h"
#include "intro.h"
#include "menu.h"
#include "selecionar.h"

int main()
{
    int lang; // language -> 0- pt, 1- en

    //intro();
    lang=selecionar();

    getch();
    system("cls");

    menu(lang);

    return 0;
}
