#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.c>
#include <time.h>
#include "addmusic.h"
#include "cores.h"
#include "idioma.h"
#include "intro.h"
#include "menu.h"

int main()
{
    int lang=0,cor=0,opc=0;   // language -> 0- pt, 1- en     cor -> 0- default
    setlocale(LC_ALL,"Portuguese");
    textcolor(15);

    intro();
    opc=menu(lang,cor);

    return 0;
}
