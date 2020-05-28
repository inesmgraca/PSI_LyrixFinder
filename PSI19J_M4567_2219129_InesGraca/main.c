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
#include "login.h"
#include "menu.h"

int main()
{
    int a=0,admin;                      //0- regular user, 1- admin
    setlocale(LC_ALL,"Portuguese");
    textcolor(15);

    intro();

    login:
    admin=login();
    a=menu(admin);

    if (a==1)
    {
        goto login;
    }
    else
    {
        return 0;
    }
}
