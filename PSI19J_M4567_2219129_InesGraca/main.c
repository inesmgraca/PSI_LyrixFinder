#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.c>
#include <string.h>
#include <time.h>
#include "addmusic.h"
#include "cores.h"
#include "idioma.h"
#include "intro.h"
#include "menu.h"

int main()
{
    int opc=0;
    setlocale(LC_ALL,"Portuguese");
    textcolor(15);

    intro();
    //login();
    opc=menu();

    return 0;
}
